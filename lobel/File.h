#ifndef FILE_H_
#define FILE_H_

#include<cstdio>

#define numof(array) (sizeof(array) / sizeof(*array))

const int TF_OVERFLOW = EOF - 1;

class CFile{
  // protected member value
protected:
  FILE *m_pfile;                // file

  // private member value
private:
  bool m_bCopy;                 // made by copy constructor

  // constructor, destructor
public:
  CFile();                      // defaut constructor
  CFile(const CFile &other);    // copy constructor
  CFile(const char *pszPath, const char *pszFlags); // constructor with parameters
  ~CFile();                     // destructor

  // file IO
public:
  bool Open(const char *pszFile, const char *pszFlags); // open file
  void Close();                                         // close file

private:
  virtual bool ModifyFlags(const char *pszSource, char *pszDest, int nSize) = 0; // modify flags

  // file controll
public:
  size_t Read(void *pDate, size_t nSize); // read file
  size_t Write(const void *pData, size_t nSize); // write file

public:
  bool IsValid() const{         // is the value of m_pfile valid
    return m_pfile != NULL;
  }
  bool Eof() const;             // does reach the end of file
};
#endif
