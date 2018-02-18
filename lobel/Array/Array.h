#ifndef ARRYA_H
#include<iostream>
#include<cstdlib>
#include<memory.h>

template<typename TYPE>
class CArray{
  // member value
private:
  TYPE *m_pnum;
  int m_nNumOf;

  // constructor, destructor
public:
  explicit CArray(const int nNumOf);
  CArray(const CArray<TYPE> &rother);
  virtual ~CArray();

  // accessor
public:
  TYPE Get(const int index) const;
  void Set(const int index, const TYPE value);

  // operator overload
  TYPE &operator[](unsigned int index);
  TYPE &operator[](int index);
  TYPE operator[](unsigned index) const;
  TYPE operator[](int index) const;

  operator const TYPE*() const;

  // check index
private:
  void CheckIndex(const int index) const;

  // function to get other information
public:
  bool IsValid() const;
  int NumOf() const;
  int SizeOf() const;

  // copy
public:
  bool Copy(const CArray<TYPE> &rother);
  CArray<TYPE> &operator=(const CArray<TYPE> &rother);

  // other functions
private:
  void Init();
  void Release();
};

template<typename TYPE>
CArray<TYPE>::CArray(const int nNumOf){
  m_pnum = new TYPE[nNumOf];
  if(m_pnum == NULL){
    m_nNumOf = 0;
  }
  else{
    m_nNumOf = nNumOf;
    memset(m_pnum, 0, nNumOf * sizeof *m_pnum);
  }
}

template<typename TYPE>
CArray<TYPE>::CArray(const CArray<TYPE> &rother){
  Init();
  Copy(rother);
}

template<typename TYPE>
CArray<TYPE>::~CArray(){
  Release();
}

template<typename TYPE>
TYPE CArray<TYPE>::Get(const int index) const{
  CheckIndex(index);
  return m_pnum[index];
}

template<typename TYPE>
void CArray<TYPE>::Set(const int index,const TYPE value){
  CheckIndex(index);
  m_pnum[index]=value;
}

template<typename TYPE>
void CArray<TYPE>::CheckIndex(const int index) const{
  if((unsigned int)index < (unsigned int)m_nNumOf){
    return;
  }

  std::cout << index << "is illegal index" << std::endl;
  exit(1);
}

template<typename TYPE>
bool CArray<TYPE>::Copy(const CArray<TYPE> &rother){
  if(m_pnum == rother.m_pnum){
    return true;
  }

  Release();

  if(rother.IsValid() == true){
    m_pnum = new TYPE[rother.NumOf()];
    if(m_pnum == NULL){
      m_nNumOf = 0;
      return false;
    }
    memcpy(m_pnum, rother.m_pnum, rother.SizeOf());
    m_nNumOf = rother.m_nNumOf;
  }

  return true;
}

template<typename TYPE>
void CArray<TYPE>::Init(){
  m_pnum = NULL;
  m_nNumOf = 0;
};

template<typename TYPE>
void CArray<TYPE>::Release(){
  if(IsValid() == true){
    delete[] m_pnum;
    Init();
  }
}

template<typename TYPE>
CArray<TYPE> &CArray<TYPE>::operator =(const CArray<TYPE> &rother){
  Copy(rother);
  return *this;
}

template<typename TYPE>
TYPE &CArray<TYPE>::operator [](unsigned int index){
  CheckIndex(index);
  return m_pnum[index];
}

template<typename TYPE>
TYPE &CArray<TYPE>::operator [](int index){
  CheckIndex(index);
  return m_pnum[index];
}

template<typename TYPE>
TYPE CArray<TYPE>::operator [](unsigned int index) const{
  CheckIndex(index);
  return m_pnum[index];
}

template<typename TYPE>
TYPE CArray<TYPE>::operator [](int index) const{
  CheckIndex(index);
  return m_pnum[index];
}

template<typename TYPE>
CArray<TYPE>::operator const TYPE*() const{
  return m_pnum;
}

template<typename TYPE>
inline bool CArray<TYPE>::IsValid() const{
  return m_pnum != NULL;
}

template<typename TYPE>
int CArray<TYPE>::NumOf() const{
  return m_nNumOf;
}

template<typename TYPE>
int CArray<TYPE>::SizeOf() const{
  return m_nNumOf * sizeof(*m_pnum);
}

#endif
