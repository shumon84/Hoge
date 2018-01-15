#include<iostream>
#include<memory.h>

class CIntArray{
  // private member value
private:
  int *m_pnum;                  // dynamic array
  int m_nNumOf;                 // number of element of dynamic array

  // constructor, destructor
public:
  CIntArray(const int nNumOf);
  CIntArray(CIntArray &other);
  ~CIntArray();

  // accessor
public:
  int Get(const int index);
  void Set(const int index, const int value);

  // public member function
public:
  // is succeded in memory allocation
  bool Success(){
    return m_pnum != NULL;
  }

  // number of element of dynamic array
  int NumOf(){
    return m_nNumOf;
  }

  // memory size of dynamic array
  int SizeOf(){
    return m_nNumOf * sizeof(*m_pnum);
  }

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

// copy constructor
CIntArray::CIntArray(CIntArray &other){
  std::cout << "CIntArray Copy Constructor Called. ";
  std::cout << "Number of Elemet is " << other.NumOf() << "." << std::endl;
  if(other.Success() == false){
    m_pnum = NULL;
    m_nNumOf = 0;
  }
  else{
    m_pnum = new int[other.NumOf()];
    if(m_pnum == NULL){
      m_nNumOf = 0;
      return;
    }
    memcpy(m_pnum, other.m_pnum, other.SizeOf());
    m_nNumOf = other.m_nNumOf;
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

void Disp(CIntArray array){
  for(int i = 0; i < array.NumOf(); ++i){
    std::cout << array.Get(i) << ' ';
  }
  std::cout << std::endl;
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

  std::cout << "   exit : 0" << std::endl;
  std::cout << "    Get : 1" << std::endl;
  std::cout << "    Set : 2" << std::endl;
  std::cout << "Success : 3" << std::endl;
  std::cout << "  NumOf : 4" << std::endl;
  std::cout << " SizeOf : 5" << std::endl;
  std::cout << "   Disp : 6" << std::endl;

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
    case 3:
      std::cout << "Success = " << a.Success() << std::endl;
      break;
    case 4:
      std::cout << "NumOf = " << a.NumOf() << std::endl;
      break;
    case 5:
      std::cout << "SizeOf = " << a.SizeOf() << std::endl;
      break;
    case 6:
      Disp(a);
      break;
    default:break;
    }
  }
 END:
  return 0;
}
