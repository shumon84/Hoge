#include<cstdio>
#include<iostream>
#include<cstring>

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
  CFile();                      // constructor
  CFile(const CFile &other);    // copy constructor
  ~CFile();                     // destructor

  // file IO
public:
  bool Open(const char *pszFile, const char *pszFlags); // open file
  void Close();                                         // close file

private:
  bool ModifyFlags(const char *pszSource, char *pszDest, int nSize); // modify flags

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

CFile::CFile(){
  m_pfile = NULL;
  m_bCopy = false;
}

CFile::CFile(const CFile &other){
  m_pfile = other.m_pfile;
  m_bCopy = true;
}

CFile::~CFile(){
  if(m_bCopy == false){
    Close();
  }
}

bool CFile::Open(const char *pszFile, const char *pszFlags){
  std::cout << "CFile::Open" << std::endl;

  Close();

  char bufFlags[8];
  if(ModifyFlags(pszFlags, bufFlags, numof(bufFlags)) == false){
    return false;
  }

  m_pfile = fopen(pszFile, bufFlags);
  return m_pfile != NULL;
}

void CFile::Close(){
  if(IsValid() == true){
    fclose(m_pfile);
    m_pfile = 0;
  }
}

bool CFile::ModifyFlags(const char *pszSource, char *pszDest, int nSize){
  std::cout << "CFile::ModifyFlags" << std::endl;

  bool bBinary;
  bBinary = (strchr(pszSource, 'b') != NULL);

  if((int)strlen(pszSource) > nSize - 1){
    return false;
  }

  strcpy(pszDest, pszSource);

  if(bBinary == false){
    strcat(pszDest, "b");
  }

  return true;
}

size_t CFile::Read(void *pData, size_t nSize){
  if(IsValid() == false){
    return 0;
  }
  return fread(pData, 1, nSize, m_pfile);
}

size_t CFile::Write(const void* pData, size_t nSize){
  if(IsValid() == false){
    return 0;
  }
  return fwrite(pData, 1, nSize, m_pfile);
}

bool CFile::Eof() const{
  if(IsValid() == false){
    return true;
  }
  return feof(m_pfile) != 0;
}

class CTextFile:public CFile{
public:
  int WriteString(const char *pszString){ // Write text
    return Write(pszString, strlen(pszString));
  }
  int ReadLine(char *buffer, size_t nSize); // Read a line

  // public override function
public:
  bool Open(const char *pszFile, const char *pszFlags);

  // private override function
private:
  bool ModifyFlags(const char *pszSource, char *pszDest, int nSize);
};

int CTextFile::ReadLine(char *buffer, size_t nSize){
  if(IsValid() == false){
    return EOF;
  }
  if(fgets(buffer, nSize, m_pfile) == NULL){
    return EOF;
  }

  size_t nLength = strlen(buffer);

  if(buffer[nLength - 1] != '\n'){
    return (nLength == nSize - 1) ? TF_OVERFLOW : nLength;
  }

  nLength -= 1;
  buffer[nLength] = 0;
  return nLength;
}

bool CTextFile::Open(const char *pszFile, const char *pszFlags){
  std::cout << "CTextFile::Open" << std::endl;

  Close();

  char bufFlags[8];
  if(ModifyFlags(pszFlags, bufFlags, numof(bufFlags)) == false){
    return false;
  }

  m_pfile = fopen(pszFile, bufFlags);

  return m_pfile != NULL;
}

bool CTextFile::ModifyFlags(const char *pszSource, char *pszDest, int nSize){
  std::cout << "CTextFile::ModifyFlags" << std::endl;

  bool bBinary;

  bBinary = (strchr(pszSource, 'b') != NULL);

  if((int)strlen(pszSource) - bBinary > nSize - 1){
    return false;
  }

  for(;*pszSource;pszSource++){
    if(*pszSource != 'b'){
      *pszDest = *pszSource;
      pszDest++;
    }
  }
  return true;
}

void Viss(const int num){
  std::cout << "Viss : No." << num << std::endl;
}

int main(void){
  CFile bin;
  CTextFile txt;

  Viss(1);
  bin.Open("Test.txt", "r");
  Viss(2);
  txt.Open("Test.txt", "r");
  Viss(3);

  return 0;
}
