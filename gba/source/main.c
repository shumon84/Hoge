#include<gba.h>

void WaitForVsync(void){
  while(*(vu16*)0x4000006 >= 160);
  while(*(vu16*)0x4000006 < 160);
}

void Mode3PutPixel(unsigned x, unsigned y, unsigned col){
  static u16 *ScreenBuffer = (u16*)0x06000000;
  ScreenBuffer[y * 240 + x] = col;
}

int main(void){
  SetMode(MODE_3 | BG2_ENABLE);

  u32 x = 50;
  u32 y = 50;
  u16 col = RGB5(31,31,31);

  Mode3PutPixel(x,y,col);

  while(1){
    WaitForVsync();
  }
}
