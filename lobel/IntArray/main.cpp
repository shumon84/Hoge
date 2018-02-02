#include<iostream>
#include"IntArray.h"
void DispArray(const CIntArray& array)
{
  int i;

  std::cout << "要素数 : " << array.NumOf() << std::endl;
  std::cout << "要素 : ";
  for(i = 0; i < array.NumOf(); i++)
    std::cout << array[i] << ' ';
  std::cout << std::endl << std::endl;
}

int main()
{
  CIntArray a1(1), a2(1), a3(10);
  int       i;

  for(i = 0; i < a3.NumOf(); i++)
    a3[i] = i;

  a1 = a2 = a3;  // 例の代入

  DispArray(a1);
  DispArray(a2);
  DispArray(a3);

  return 0;
}
