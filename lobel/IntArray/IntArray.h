#ifndef __INTARRAY_H_INCLUDED__
#define __INTARRAY_H_INCLUDED__

#include<cstddef>

class CIntArray{
  // メンバ変数
private:
  int* m_pnum;   // 動的配列
  int m_nNumOf; // 配列の要素数

  // コンストラクタ・デストラクタ
public:
  CIntArray(const int nNumOf);
  CIntArray(const CIntArray &rother);  // コピーコンストラクタ
  ~CIntArray();

  // コピー
public:
  bool Copy(const CIntArray &rother); // 配列のコピー

  // 諸関数
private:
  void Init(); // メンバの初期化
  void Release(); // メモリの解放

  // メンバへのアクセス関数
public:
  int Get(const int index) const;
  void Set(const int index, const int value);

  // インデックスのチェック
private:
  void CheckIndex(const int index) const;

  // その他の情報の取得
public:
  bool IsValid() const;  // メモリの確保が成功したか
  int NumOf() const;     // 配列の要素数
  int SizeOf() const;    // 配列のサイズ

  // 演算子オーバーロード
public:
  void operator = (const CIntArray &rother);
};

// メモリの確保が成功したか
inline bool CIntArray::IsValid() const{
  return m_pnum != NULL;
}

// 配列の要素数
inline int CIntArray::NumOf() const{
  return m_nNumOf;
}

// 配列のサイズ
inline int CIntArray::SizeOf() const{
  return m_nNumOf * sizeof *m_pnum;
}

#endif
