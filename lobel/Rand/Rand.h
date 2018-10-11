#ifndef RAND_H
#define RAND_H
#include <stddef.h>
#include <time.h>

// unsigned は unsigned int と同等です
template <unsigned TMPL_BITS = 15,
          unsigned TMPL_A    = 48828125,
          unsigned TMPL_C    = 1>
class CRandTmpl
{
private:
  unsigned m_nSeed;  // 乱数種

  // 定数群
public:
  static const unsigned BITS;  // 使用する上位ビットの数
  static const unsigned MAX;   // 乱数の上限
  static const unsigned A;     // 傾き
  static const unsigned C;     // 切片

public:
  // 初期化
  void Init(unsigned nSeed){ m_nSeed = nSeed; }
  CRandTmpl(unsigned nSeed){ Init(nSeed); }

  // 現在の時間で初期化
  void Init(){ Init((unsigned)time(NULL)); }
  CRandTmpl(){ Init(); }

  // 乱数種の取得
  unsigned GetSeed(){ return m_nSeed; }

  // 疑似乱数生成
  int Rand();
  operator int()     { return Rand(); }
  operator unsigned(){ return Rand(); }

  // [0, 1)（０以上１未満）の疑似乱数生成
  double RandD();
  operator double(){ return RandD(); }

  // ある数未満の乱数を生成
  int Rand(int nLimit);
};

////////////////////////////////////////////////////////////////
// 定数群

// 使用する上位ビットの数
template <unsigned TMPL_BITS, unsigned TMPL_A, unsigned TMPL_C>
const unsigned CRandTmpl <TMPL_BITS, TMPL_A, TMPL_C> ::
BITS = TMPL_BITS;

// 乱数の上限
template <unsigned TMPL_BITS, unsigned TMPL_A, unsigned TMPL_C>
const unsigned CRandTmpl <TMPL_BITS, TMPL_A, TMPL_C> ::
MAX = (1 << TMPL_BITS) - 1;

// 傾き
template <unsigned TMPL_BITS, unsigned TMPL_A, unsigned TMPL_C>
const unsigned CRandTmpl <TMPL_BITS, TMPL_A, TMPL_C> ::
A = TMPL_A;

// 切片
template <unsigned TMPL_BITS, unsigned TMPL_A, unsigned TMPL_C>
const unsigned CRandTmpl <TMPL_BITS, TMPL_A, TMPL_C> ::
C = TMPL_C;

////////////////////////////////////////////////////////////////
// メンバ関数の実装

// 疑似乱数生成
template <unsigned TMPL_BITS, unsigned TMPL_A, unsigned TMPL_C>
int CRandTmpl <TMPL_BITS, TMPL_A, TMPL_C> ::
Rand()
{
  m_nSeed = m_nSeed * TMPL_A + TMPL_C;
  // 上位ビットを返します
  return m_nSeed >> (32 - TMPL_BITS);
}

// [0, 1)（０以上１未満）の疑似乱数生成
template <unsigned TMPL_BITS, unsigned TMPL_A, unsigned TMPL_C>
inline double CRandTmpl <TMPL_BITS, TMPL_A, TMPL_C> ::
RandD()
{
  return (double)Rand() * (1.0 / (MAX + 1));
}

// ある数未満の乱数を生成
template <unsigned TMPL_BITS, unsigned TMPL_A, unsigned TMPL_C>
inline int CRandTmpl <TMPL_BITS, TMPL_A, TMPL_C> ::
Rand(int nLimit)
{
  // % nLimit よりも上質の分布になります
  // ただし、１６ビット機では long でやらないといけません
  return Rand() * nLimit / (MAX + 1);
}

// 普通は CRand を使えば充分、という風にしておきます
typedef CRandTmpl <> CRand;
#endif
