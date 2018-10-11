#ifndef TEXTFILE_H_
#define TEXTFILE_H_

#include<cstring>
#include"File.h"

class CTextFile : public CFile{
public:
  CTextFile();
  CTextFile(const char *pszPath, const char *pszFlags);
  CTextFile(const CTextFile &rother);
  ~CTextFile();

public:
  int WriteString(const char *pszString){ // Write text
    return Write(pszString, strlen(pszString));
  }
  int ReadLine(char *buffer, size_t nSize); // Read a line

  // public override function
public:
  //bool Open(const char *pszFile, const char *pszFlags);

  // private override function
private:
  virtual bool ModifyFlags(const char *pszSource, char *pszDest, int nSize);
};
#endif
