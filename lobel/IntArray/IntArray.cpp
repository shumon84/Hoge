#include<iostream>
#include<memory>
#include"IntArray.h"

using namespace std;

// コンストラクタ
CIntArray::CIntArray(const int nNumOf)
{
  m_pnum = new int[nNumOf];
  if(m_pnum == NULL)
    m_nNumOf = 0;
  else
    {
      m_nNumOf = nNumOf;
      memset(m_pnum, 0, nNumOf * sizeof *m_pnum);
    }

  cout << "コンストラクタが呼ばれました。"
       << "要素数は " << m_nNumOf << " です。" << endl;
}

// コピーコンストラクタ
CIntArray::CIntArray(const CIntArray& rother)
{
  if(rother.Success() == false)
    {
      m_pnum   = NULL;
      m_nNumOf = 0;
    }
  else
    {
      m_pnum = new int[rother.NumOf()];
      if(m_pnum == NULL)
        {
          m_nNumOf = 0;
          return;
        }

      // memcpy はメモリの内容をバイト単位でコピーする関数です
      memcpy(m_pnum, rother.m_pnum, rother.SizeOf());
      m_nNumOf = rother.m_nNumOf;
    }

  cout << "コピーコンストラクタが呼ばれました。" << endl;
}

// デストラクタ
CIntArray::~CIntArray()
{
  if(m_pnum != NULL)
    delete [] m_pnum;

  cout << "デストラクタが呼ばれました。"
       << "要素数は " << m_nNumOf << " でした。" << endl;
}

// メンバへのアクセス関数
int CIntArray::Get(const int index) const
{
  CheckIndex(index);
  return m_pnum[index];
}

void CIntArray::Set(const int index, const int value)
{
  CheckIndex(index);
  m_pnum[index] = value;
}

// インデックスのチェック
void CIntArray::CheckIndex(const int index) const
{
  if((unsigned int)index < (unsigned int)m_nNumOf)
    return;

  cout << "インデックスが不正です！" << endl
       << "値 : " << index << endl;
  exit(1);
}
