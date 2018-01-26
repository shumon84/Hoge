#include"TextFile.h"
#include<iostream>

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

CTextFile::CTextFile(){
  std::cout << "CTextFile()" << std::endl;
}

CTextFile::CTextFile(const char *pszPath, const char *pszFlags){
  std::cout << "CTextFile(const char *pszPath, const char *pszFlags)" << std::endl;
  Open(pszPath, pszFlags);
}

CTextFile::CTextFile(const CTextFile &rother) : CFile(rother){
    std::cout << "CTextFile(const CTextFile &rother)" << std::endl;
}

CTextFile::~CTextFile(){
  std::cout << "CTextFile::~CTextFile()" << std::endl;
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
