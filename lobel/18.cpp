#include<cstdio>
#include<iostream>
#include<cstring>
#include<cctype>

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

CFile::CFile(){
  m_pfile = NULL;
  m_bCopy = false;
}

CFile::CFile(const CFile &other){
  m_pfile = other.m_pfile;
  m_bCopy = true;
}

// construct, and open file same time
CFile::CFile(const char *pszPath, const char *pszFlags){
  m_pfile = NULL;
  m_bCopy = false;
  Open(pszPath, pszFlags);
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
    m_pfile = NULL;
  }
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
  CTextFile();
  CTextFile(const char *pszPath, const char *pszFlags);
  CTextFile(const CTextFile &rother);

public:
  int WriteString(const char *pszString){ // Write text
    return Write(pszString, strlen(pszString));
  }
  int ReadLine(char *buffer, size_t nSize); // Read a line

  // private override function
private:
  virtual bool ModifyFlags(const char *pszSource, char *pszDest, int nSize);
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

CTextFile::CTextFile() : CFile(){
  std::cout << "Add CTextFile()" << std::endl;
}

CTextFile::CTextFile(const char *pszPath, const char *pszFlags) : CFile(pszPath, pszFlags){
  std::cout << "Add CTextFile(const char *pszPath, const char *pszFlags)" << std::endl;
  Open(pszPath, pszFlags);
}

CTextFile::CTextFile(const CTextFile &rother) : CFile(rother){
    std::cout << "Add CTextFile(const CTextFile &rother)" << std::endl;
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

class CBinaryFile : public CFile{
  // constructor
public:
  CBinaryFile();
  CBinaryFile(const char *pszPath, const char *pszFlags);
  CBinaryFile(const CBinaryFile &rother);

public:
  int ReadAndDump(char *bufHex, char *bufASCII, int nLength);

private:
  bool ModifyFlags(const char *pszPath, const char *pszFlags);
};

CBinaryFile::CBinaryFile() : CFile(){
}

CBinaryFile::CBinaryFile(const char *pszPath, const char *pszFlags) : CFile(pszPath, pszFlags){
  Open(pszPath, pszFlags);
}

CBinaryFile::CBinaryFile(const CBinaryFile &rother) : CFile(rother){
}

int CBinaryFile::ReadAndDump(char *bufHex, char *bufASCII, int nLength){
  int nRead;
  int i;

  nRead = Read(bufASCII, nLength);
  memset(bufASCII + nRead, ' ', nLength - nRead);
  bufASCII[nLength] = 0;

  for(i = 0; i < nRead; i++){
    sprintf(&bufHex[i * 3], "%02X", (unsigned char)bufASCII[i]);
  }

  memset(&bufHex[i * 3], ' ', (nLength - nRead) * 3);
  bufHex[nLength * 3] = 0;

  for(i = 0; i < nRead; i++){
    if(isprint((unsigned char)bufASCII[i]) == 0){
      bufASCII[i] = '.';
    }
  }

  return nRead;
}

bool CBinaryFile::ModifyFlags(const char *pszSource, const char *pszDest){
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


int main(){
  CTextFile txt("Test.txt", "w");
  if(txt.IsValid() == false){
    return 0;
  }

  txt.WriteString("He Song, \"まったりまったりまったりな〜♪\"");
  txt.Close();

  CBinaryFile bin("Test.txt", "r");
  if(bin.IsValid() == false){
    return 0;
  }

  const int READLENGTH = 16;
  char bufHex[READLENGTH * 3 + 1];
  char bufASCII[READLENGTH + 1];
  int nRead;

  do{
    nRead = bin.ReadAndDump(bufHex, bufASCII, READLENGTH);
    std::cout << bufHex << bufASCII << std::endl;
  }while(nRead == READLENGTH);

  return 0;
}
