#include"File.h"
#include<iostream>

CFile::CFile(){
  std::cout << "CFile()" << std::endl;
  m_pfile = NULL;
  m_bCopy = false;
}

CFile::CFile(const CFile &other){
  std::cout << "CFile(const CFile &rother)" << std::endl;
  m_pfile = other.m_pfile;
  m_bCopy = true;
}

// construct, and open file same time
CFile::CFile(const char *pszPath, const char *pszFlags){
  std::cout << "CFile(const char *pszPathm const char *pszFlags)" << std::endl;
  m_pfile = NULL;
  m_bCopy = false;
  Open(pszPath, pszFlags);
}

CFile::~CFile(){
  std::cout << "~CFile()" << std::endl;
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
