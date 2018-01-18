#include<iostream>
#include<memory.h>

#define ELEM(array) sizeof(array) / sizeof(int)

class CIntArray{
private:
  int m_anum[100];

public:
  CIntArray();

public:
  int Get(const int index);
  void Set(const int index, const int value);

private:
  void CheckIndex(const int index);
};

// constructor
CIntArray::CIntArray(){
  memset(m_anum, 0, sizeof(m_anum));
}

int CIntArray::Get(const int index){
  CheckIndex(index);
  return m_anum[index];
}

void CIntArray::Set(const int index, const int value){
  CheckIndex(index);
  m_anum[index] = value;
}

void CIntArray::CheckIndex(const int index){
  if((unsigned int)index < ELEM(m_anum))
    return;

  std::cout << "fatal error : Invalid Index." << std::endl;
  std::cout << "value : " << index << std::endl;

  exit(1);
}

#include<cstdio>
int main(int argc, char *argv[]){
  CIntArray a;
  int select;
  int index;
  int m_anum;

  std::cout << "exit : 0" << std::endl;
  std::cout << "Get : 1" << std::endl;
  std::cout << "Set : 2" << std::endl;

  while(1){
    std::cout << "$ ";
    std::cin >> select;
    switch(select){
    case 0:
      exit(0);
    case 1:
      std::cout << "index : ";
      std::cin >> index;
      std::cout << "Get(" << index << ") = " << a.Get(index) << std::endl;
      break;
    case 2:
      std::cout << "index : ";
      std::cin >> index;
      std::cout << "m_anum : ";
      std::cin >> m_anum;
      a.Set(index, m_anum);
      break;
    }
  }
}
