#include<iostream>
#include<memory>
#include"IntArray.h"

// コンストラクタ
CIntArray::CIntArray(const int nNumOf){
  m_pnum = new int[nNumOf];
  if(m_pnum == NULL){
    m_nNumOf = 0;
  }
  else{
    m_nNumOf = nNumOf;
    memset(m_pnum, 0, nNumOf * sizeof *m_pnum);
  }

  std::cout << "コンストラクタが呼ばれました。"  << "要素数は " << m_nNumOf << " です。" << std::endl;
}

// コピーコンストラクタ
CIntArray::CIntArray(const CIntArray &rother){
  if(rother.IsValid() == false){
    m_pnum   = NULL;
    m_nNumOf = 0;
  }
  else{
    m_pnum = new int[rother.NumOf()];
    if(m_pnum == NULL){
      m_nNumOf = 0;
      return;
    }
    memcpy(m_pnum, rother.m_pnum, rother.SizeOf());
    m_nNumOf = rother.m_nNumOf;
  }

  std::cout << "コピーコンストラクタが呼ばれました。" << std::endl;
}

// デストラクタ
CIntArray::~CIntArray(){
  if(m_pnum != NULL){
    delete [] m_pnum;
  }
  std::cout << "デストラクタが呼ばれました。" << "要素数は " << m_nNumOf << " でした。" << std::endl;
}

// メンバへのアクセス関数
int CIntArray::Get(const int index) const{
  CheckIndex(index);
  return m_pnum[index];
}

void CIntArray::Set(const int index, const int value){
  CheckIndex(index);
  m_pnum[index] = value;
}

// インデックスのチェック
void CIntArray::CheckIndex(const int index) const{
  if(IsValid() == true && (unsigned int)index < (unsigned int)m_nNumOf){
    return;
  }

  std::cout << "インデックスが不正です！" << std::endl << "値 : " << index << std::endl;
  exit(1);
}

bool CIntArray::Copy(const CIntArray &rother){
  if(m_pnum == rother.m_pnum){
    return true;
  }

  Release();

  if(rother.IsValid() == true){
    m_pnum = new int[rother.NumOf()];
    if(m_pnum == NULL){
      m_nNumOf = 0;
      return false;
    }

    memcpy(m_pnum, rother.m_pnum, rother.SizeOf());
    m_nNumOf = rother.m_nNumOf;
  }

  return true;
}

void CIntArray::Init(){
  m_pnum = NULL;
  m_nNumOf = 0;
}

void CIntArray::Release(){
  if(IsValid() == true){
    delete [] m_pnum;
    Init();
  }
}

void CIntArray::operator =(const CIntArray &rother){
  Copy(rother);
}

int &CIntArray::operator [](int index){
  CheckIndex(index);
  return m_pnum[index];
}

int CIntArray::operator [](int index) const{
  CheckIndex(index);
  return m_pnum[index];
}
