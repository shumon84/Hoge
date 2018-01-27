#include<iostream>
#include"EncFile.h"

const unsigned char XOR_FACTOR = 0xAA; // Encryption key

CEncodeFile::CEncodeFile(){
  std::cout << "CEncodeFile::CEncodeFile()" << std::endl;
}

CEncodeFile::CEncodeFile(const char *pszPath, const char *pszFlags){
  std::cout << "CEncodeFile::CEncodeFile(const char *pszPath, const char *pszFlags)" << std::endl;

  Open(pszPath, pszFlags);
}

CEncodeFile::CEncodeFile(const CEncodeFile &other) : CBinaryFile(other){
  std::cout << "CEncodeFile::CEncodeFile(const CEncodeFile &other)" << std::endl;
}

CEncodeFile::~CEncodeFile(){
  std::cout << "CEncodeFile::~CEncodeFile()" << std::endl;
}

size_t CEncodeFile::Read(void *buffer, size_t nSize){
  size_t nRead;
  nRead = Read(buffer, nSize);
  Decode(buffer, nRead);

  return nRead;
}

size_t CEncodeFile::Write(const void *buffer, size_t nSize){
  unsigned char *bufEncode;
  size_t nWrite;

  if(nSize == EF_OUTOFMEMORY){
    return EF_OUTOFMEMORY;
  }

  bufEncode = new unsigned char[nSize];

  if(bufEncode == NULL){
    return EF_OUTOFMEMORY;
  }

  Encode(bufEncode, buffer, nSize);
  nWrite = Write(bufEncode, nSize);

  delete [] bufEncode;
  return nWrite;
}

void CEncodeFile::Encode(void *bufDest, const void *bufSrc, size_t nSize){
  size_t i;
  for (i = 0; i < nSize; i++){
    ((unsigned char *)bufDest)[i] = ((const unsigned char *)bufSrc)[i] ^ XOR_FACTOR;
  }
}

void CEncodeFile::Decode(void *buffer, size_t nSize){
  size_t i;
  for (i = 0; i < nSize; i++){
    ((unsigned char *)buffer)[i] ^= XOR_FACTOR;
  }
}
