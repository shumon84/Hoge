#include"BinFile.h"
#include<cctype>
#include<memory>
#include<iostream>
#include<cstring>

CBinaryFile::CBinaryFile(){
  std::cout << "CBinaryFile()" << std::endl;
}

CBinaryFile::CBinaryFile(const char *pszPath, const char *pszFlags){
  std::cout << "CBinaryFile(const char *pszPath, const char *pszFlags)" << std::endl;
  Open(pszPath, pszFlags);
}

CBinaryFile::CBinaryFile(const CBinaryFile &rother) : CFile(rother){
  std::cout << "CBinaryFile(const CBinaryFile &rother)" << std::endl;
}

CBinaryFile::~CBinaryFile(){
  std::cout << "~CBinaryFile()" << std::endl;
}

int CBinaryFile::ReadAndDump(char *bufHex, char *bufASCII, int nLength){
  int nRead;
  int i;

  nRead = Read(bufASCII, nLength);
  memset(bufASCII + nRead, ' ', nLength - nRead);
  bufASCII[nLength] = 0;

  for (i = 0; i < nRead; i++){
    sprintf(&bufHex[i * 3], "%02X", (unsigned char)bufASCII[i]);
  }

  memset(&bufHex[i * 3],  ' ', (nLength - nRead) * 3);
  bufHex[nLength * 3] = 0;

  for (i = 0; i < nRead; i++){
    if(isprint((unsigned char)bufASCII[i]) == 0){
      bufASCII[i] = '.';
    }
  }

  return nRead;
}

bool CBinaryFile::ModifyFlags(const char *pszPath, char *pszFlags, int nSize){
  std::cout << "CBinaryFile::ModifyFlags" << std::endl;

  bool bBinary;
  bBinary = (strchr(pszPath, 'b') != NULL);

  if((int)strlen(pszPath) > nSize - 1){
    return false;
  }

  strcpy(pszFlags, pszPath);

  if(bBinary == false){
    strcat(pszFlags, "b");
  }

  return true;

}
