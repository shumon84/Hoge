#include<cstdio>
#include"Array.h"

int main(){
  static const char str1[] = "Schroedingerの猫";
  CArray<char> str2(sizeof(str1));
  CArray<char> str3(0);
  int i;

  for(i = 0; i < str2.NumOf(); i++){
    str2[i] = str1[i];
  }

  std::cout << str2 << std::endl;

  char dog[] = "犬";
  str3 = str2;
  str3[(int)sizeof(str1) - 4] = dog[0];
  str3[(int)sizeof(str1) - 3] = dog[1];
  str3[(int)sizeof(str1) - 2] = dog[2];
  str3[(int)sizeof(str1) - 1] = dog[3];
  printf("%s\n",(const char*)str3);
}
