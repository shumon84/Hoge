#include<iostream>
#include<memory>
#include"IntArray.h"

// コンストラクタ
CIntArray::CIntArray(const int nNumOf) : m_nNumOf(nNumOf){
  m_pnum = new int[nNumOf];
  if(m_pnum == NULL){
    memset(m_pnum, 0, nNumOf * sizeof *m_pnum);
  }

  std::cout << "コンストラクタが呼ばれました。"  << "要素数は " << m_nNumOf << " です。" << std::endl;
}

// コピーコンストラクタ
CIntArray::CIntArray(const CIntArray &rother) : m_nNumOf(rother.NumOf()){
  if(rother.Success() == false){
    m_pnum   = NULL;
  }
  else{
    m_pnum = new int[rother.NumOf()];
    if(m_pnum != NULL){
      memcpy(m_pnum, rother.m_pnum, rother.SizeOf());
    }
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
  if(Success() == true && (unsigned int)index < (unsigned int)m_nNumOf){
    return;
  }

  std::cout << "インデックスが不正です！" << std::endl << "値 : " << index << std::endl;
  exit(1);
}
