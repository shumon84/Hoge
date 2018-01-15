#include<iostream>
#include<memory.h>

class CIntArray{
  // private member value
private:
  int *m_pnum;                  // dynamic array
  int m_nNumOf;                 // number of element of m_pnum

  // constructor, destructor
public:
  CIntArray(const int nNumOf);
  ~CIntArray();

  // accessor
public:
  int Get(const int index);
  void Set(const int index, const int value);

  // private member function
private:
  void CheckIndex(const int index);
};

// constructor
CIntArray::CIntArray(const int nNumOf){
  std::cout << "CIntArray Constructor Called. ";
  std::cout << "Number of Elemet is " << nNumOf << "." << std::endl;
  m_pnum = new int[nNumOf];
  if(m_pnum == NULL){
    m_nNumOf = 0;
  }
  else{
    m_nNumOf = nNumOf;
    memset(m_pnum, 0, nNumOf * sizeof(*m_pnum));
  }
}

// destructor
CIntArray::~CIntArray(){
  std::cout << "CIntArray Destructor Called. ";
  std::cout << "Number of Elemet is " << m_nNumOf << "." << std::endl;
  if(m_pnum != NULL)
    delete[] m_pnum;
}

// accessor
int CIntArray::Get(const int index){
  CheckIndex(index);
  return m_pnum[index];
}

// accessor
void CIntArray::Set(const int index, const int value){
  CheckIndex(index);
  m_pnum[index] = value;
}

// private member function
void CIntArray::CheckIndex(const int index){
  if(index < m_nNumOf)
    return;

  std::cout << "fatal error : Invalid Index." << std::endl;
  std::cout << "value : " << index << std::endl;

  exit(1);
}

#include<cstdio>
int main(int argc, char *argv[]){
  int select;
  int index;
  int value;
  int nNumOf;
  std::cout << "Number of Element of Array : ";
  std::cin >> nNumOf;
  CIntArray a(nNumOf);

  std::cout << "exit : 0" << std::endl;
  std::cout << "Get : 1" << std::endl;
  std::cout << "Set : 2" << std::endl;

  while(1){
    std::cout << "$ ";
    std::cin >> select;
    switch(select){
    case 0:
      goto END;
    case 1:
      std::cout << "index : ";
      std::cin >> index;
      std::cout << "Get(" << index << ") = " << a.Get(index) << std::endl;
      break;
    case 2:
      std::cout << "index : ";
      std::cin >> index;
      std::cout << "m_anum : ";
      std::cin >> value;
      a.Set(index, value);
      break;
    }
  }
 END:
  return 0;
}
