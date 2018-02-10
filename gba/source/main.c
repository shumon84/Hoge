#include<gba.h>
#include"zero.h"

void WaitForVsync(void){
  while(*(vu16*)0x4000006 >= 160);
  while(*(vu16*)0x4000006 < 160);
}

void Mode3PutPixel(unsigned x, unsigned y, unsigned col){
  static u16 *ScreenBuffer = (u16*)0x06000000;
  ScreenBuffer[y * 240 + x] = col;
}

void Mode3DrawBox(u32 x1, u32 y1, u32 x2, u32 y2, u16 col){
  u32 x, y;

  for(y=y1;y<y2;y++)
    for(x=x1;x<x2;x++)
      Mode3PutPixel(x,y,col);
}

void Mode3DrawImage(unsigned x,unsigned y,const unsigned short *image){
  int i,j;
  for(i=0;i<41;i++)
    for(j=0;j<34;j++)
      if(image[i*34+j]!=RGB5(31,31,31))
        Mode3PutPixel(j+x,i+y,image[i*34+j]);
}

void SpriteMove(u32 num,s32 x,s32 y){
  OBJATTR *sp=(OBJATTR*)OAM +num;
  sp->attr1 &= 0xfe00;
  sp->attr0 &= 0xff00;
  sp->attr1 |= (x & 0x01ff);
  sp->attr0 |= (y & 0x00ff);
}

void SpriteInit(void){
  u32 i;
  for(i=0;i<128;i++){
    SpriteMove(i,240,160);
  }
}

void SpriteSetSize(u32 num, u32 size, u32 from, u32 col){
  OBJATTR *sp = (OBJATTR*)OAM + num;
  sp->attr0 &= 0x1fff;
  sp->attr1 &= 0x3fff;
  sp->attr0 |= col | from | (160);
  sp->attr1 |= size | (240);
}

void SpriteSetChr(u32 num, u32 ch){
  OBJATTR *sp = (OBJATTR*)OAM + num;
  sp->attr2 &= 0xfc00;
  sp->attr2 |= ch;
}

#include"zero_stand.h"

int main(void){
  // モード設定
  SetMode(MODE_0 | OBJ_ENABLE | OBJ_1D_MAP);
  u16* oam = OBJ_BASE_ADR;// キャラクタデータ
  u16* pal = OBJ_COLORS;// パレットデータ
  u32 i;
  u32 sprTilesLen=10;
  u32 sprTiles[256];
  u32 sprPal[16];

  for(i=0; i<sprTilesLen/2; i++)
    {
      oam[i] = sprTiles[i];
    }

  for(i=0; i<16; i++)
    {
      pal[i] = sprPal[i];
    }

  SpriteInit();

  // !（ビックリマーク）の表示
  SpriteSetSize(0, OBJ_SIZE(Sprite_8x8), OBJ_SQUARE, OBJ_16_COLOR);
  SpriteSetChr (0, 1);
  SpriteMove   (0, 20, 20);

  u32 x = 40;
  u32 y = 40;

  // 円の表示
  SpriteSetSize(1, OBJ_SIZE(Sprite_32x32), OBJ_SQUARE, OBJ_16_COLOR);
  SpriteSetChr (1, 224);
  SpriteMove   (1, x, y);

  for(;;)
    {
      WaitForVsync();

      if( !(REG_KEYINPUT & KEY_UP)   ) y--;
      if( !(REG_KEYINPUT & KEY_DOWN) ) y++;
      if( !(REG_KEYINPUT & KEY_LEFT) ) x--;
      if( !(REG_KEYINPUT & KEY_RIGHT)) x++;
      SpriteMove   (1, x, y);
    }

}
