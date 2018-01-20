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

// bool CTextFile::Open(const char *pszFile, const char *pszFlags){
//   std::cout << "CTextFile::Open" << std::endl;

//   Close();

//   char bufFlags[8];
//   if(ModifyFlags(pszFlags, bufFlags, numof(bufFlags)) == false){
//     return false;
//   }

//   m_pfile = fopen(pszFile, bufFlags);

//   return m_pfile != NULL;
// }

CTextFile::CTextFile() : CFile(){
  std::cout << "CTextFile()" << std::endl;
}

CTextFile::CTextFile(const char *pszPath, const char *pszFlags){
  std::cout << "CTextFile(const char *pszPath, const char *pszFlags)" << std::endl;
  Open(pszPath, pszFlags);
}

CTextFile::CTextFile(const CTextFile &rother) : CFile(rother){
    std::cout << "CTextFile(const CTextFile &rother)" << std::endl;
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
