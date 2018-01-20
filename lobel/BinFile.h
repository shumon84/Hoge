#ifndef BINFILE_H_
#define BINFILE_H_

#include"File.h"

class CBinaryFile : public CFile{
public:
  CBinaryFile();
  CBinaryFile(const char *pszPath, const char *pszFlags);
  CBinaryFile(const CBinaryFile &rother);

public:
  int ReadAndDump(char *bufHex, char *bufASCII, int nLength);

private:
  virtual bool ModifyFlags(const char *pszPath, char *pszFlags, int nSize);
};

#endif
