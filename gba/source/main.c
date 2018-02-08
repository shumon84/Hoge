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

#define x2 x1+30
#define y2 y1+30

int main(void){
  SetMode(MODE_3 | BG2_ENABLE);

  u32 x1 = 0;
  u32 y1 = 0;
  u16 white = RGB5(31,31,31);
  u16 red = RGB5(31,0,0);
  u16 green = RGB5(0,31,0);
  u16 blue = RGB5(0,0,31);
  u16 black = RGB5(0,0,0);
  u16 x=0,y=0;
  while(1){
    WaitForVsync();
    Mode3DrawImage(x,y,zeroBitmap);
    //Mode3DrawBox(x,y,x+10,y+10,black);
    if(REG_KEYINPUT & KEY_UP){
    }
    else{
      if(y>0){
        Mode3DrawBox(0,0,240,120,black);
        y--;
      }
    }
    if(REG_KEYINPUT & KEY_DOWN){
    }
    else{
      if(y<160){
        Mode3DrawBox(0,0,240,120,black);
        y++;
      }
    }
    if(REG_KEYINPUT & KEY_LEFT){
    }
    else{
      if(x>0){
        Mode3DrawBox(0,0,240,120,black);
        x--;
      }
    }
    if(REG_KEYINPUT & KEY_RIGHT){
    }
    else{
      if(x<240){
        Mode3DrawBox(0,0,240,120,black);
        x++;
      }
    }
  }
}
