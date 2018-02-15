#include<gba.h>
#include"clip_2.h"
#include"zero_stand.h"
#include"test.h"
#include"chr.h"
#include"clip_2.h"

//---------------------------------------------------------------------------
void WaitForVsync(void)
{
  while(*(vu16*)0x4000006 >= 160) {};
  while(*(vu16*)0x4000006 <  160) {};
}
//---------------------------------------------------------------------------
void SpriteSetPalNo(u32 num, u32 palNo)
{
  OBJATTR* sp = (OBJATTR*)OAM + num;

  sp->attr2 &= 0x0fff;
  sp->attr2 |= (palNo << 12);
}
//---------------------------------------------------------------------------
void SpriteMove(u32 num, s32 x, s32 y)
{
  OBJATTR* sp = (OBJATTR*)OAM + num;

  sp->attr1 &= 0xfe00;
  sp->attr0 &= 0xff00;
  sp->attr1 |= (x & 0x01ff);
  sp->attr0 |= (y & 0x00ff);
}
//---------------------------------------------------------------------------
void SpriteSetSize(u32 num, u32 size, u32 form, u32 col)
{
  OBJATTR* sp = (OBJATTR*)OAM + num;

  sp->attr0 &= 0x1fff;
  sp->attr1 &= 0x3fff;
  sp->attr0 |= col  | form | (160);
  sp->attr1 |= size | (240);
}
//---------------------------------------------------------------------------
void SpriteSetChr(u32 num, u32 ch)
{
  OBJATTR* sp = (OBJATTR*)OAM + num;

  sp->attr2 &= 0xfc00;
  sp->attr2 |= ch+16;
}
//---------------------------------------------------------------------------
void SpriteInit(void)
{
  u32 i;
  for(i=0; i<128; i++)
    {
      SpriteMove(i, 240, 160);
    }
}
//---------------------------------------------------------------------------
void SpriteShowNumber(u32 base, s32 num)
{
  s32 i;

  for(i=5-1; i>=0; i--)
    {
      SpriteSetChr(base + i, num % 10);
      num /= 10;
    }
}
//---------------------------------------------------------------------------
void SpriteSetDatChr(u16* dat, u32 size)
{
  u16* p = OBJ_BASE_ADR;
  u32 i;

  for(i=0; i<size/2; i++)
    {
      p[i] = dat[i];
    }
}
//---------------------------------------------------------------------------
void SpriteSetDatPal(u16* pal)
{
  u16* p = OBJ_COLORS;
  u32 i;

  for(i=0; i<16; i++)
    {
      p[i] = pal[i];
    }
}
//---------------------------------------------------------------------------
int main(void)
{
  // モード設定
  SetMode(MODE_0 | OBJ_ENABLE | OBJ_1D_MAP);

  SpriteInit();
  SpriteSetDatChr((u16*)&clip_2Tiles, clip_2TilesLen);
  SpriteSetDatPal((u16*)&clip_2Pal);

  u32 i;

  // タイマー0  5個のスプライトを使用
  for(i=0; i<5; i++)
    {
      SpriteSetSize (i, OBJ_SIZE(Sprite_8x8), OBJ_SQUARE, OBJ_16_COLOR);
      SpriteSetChr  (i, 0);
      SpriteMove    (i, 20+i*8, 20);
      SpriteSetPalNo(i, 0);
    }

  // タイマー1  5個のスプライトを使用
  for(i=5; i<10; i++)
    {
      SpriteSetSize (i, OBJ_SIZE(Sprite_8x8), OBJ_SQUARE, OBJ_16_COLOR);
      SpriteSetChr  (i, 0);
      SpriteMove    (i, 40+i*8, 20);
      SpriteSetPalNo(i, 0);
    }

  // タイマー設定
  REG_TM0CNT_L = 0;
  REG_TM1CNT_L = 0;
  REG_TM0CNT_H = 2 | TIMER_START;
  REG_TM1CNT_H = 1<<2 | TIMER_START;

  for(;;)
    {
      WaitForVsync();

      SpriteShowNumber(0, REG_TM0CNT_L);
      SpriteShowNumber(5, REG_TM1CNT_L);
    }
}
/* int main(void){ */
/*   // モード設定 */
/*   SetMode(MODE_0 | OBJ_ENABLE | OBJ_1D_MAP); */

/*   u16* oam = OBJ_BASE_ADR; // キャラクタデータ */
/*   u16* pal = OBJ_COLORS;  // パレットデータ */
/*   u32 i; */

/*   for(i=0; i<clip_2TilesLen/2; i++) */
/*     { */
/*       oam[i] = clip_2Tiles[i]; */
/*     } */

/*   for(i=0; i<clip_2PalLen/2; i++) */
/*     { */
/*       pal[i] = clip_2Pal[i]; */
/*     } */

/*   SpriteInit(); */

/*   // ASCII表示文字 */
/*   for(i=' ';i<'~';i++) */
/*     { */
/*       SpriteSetSize(i,OBJ_SIZE(Sprite_8x8),OBJ_SQUARE,OBJ_16_COLOR); */
/*       SpriteSetChr(i,i-' '); */
/*     } */

/*   /\* s32 x = 40; *\/ */
/*   /\* s32 y = 40; *\/ */

/*   /\* SpriteSetSize(0, OBJ_SIZE(Sprite_32x32), OBJ_SQUARE, OBJ_16_COLOR); *\/ */
/*   /\* SpriteSetChr (0, 0); *\/ */
/*   /\* SpriteMove   (0, &x, &y); *\/ */
/*   char str[]="10:21\n34,59"; */
/*   u32 len=strlen(str); */
/*   print(str,len); */
/*   for(;;) */
/*     { */
/*       WaitForVsync(); */

/*       /\* if( !(REG_KEYINPUT & KEY_UP)   ) y--; *\/ */
/*       /\* if( !(REG_KEYINPUT & KEY_DOWN) ) y++; *\/ */
/*       /\* if( !(REG_KEYINPUT & KEY_LEFT) ) x--; *\/ */
/*       /\* if( !(REG_KEYINPUT & KEY_RIGHT)) x++; *\/ */

/*       /\* SpriteMove   (0, &x, &y); *\/ */
/*     } */

/* } */
