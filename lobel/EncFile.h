#ifndef ENCFILE_H_
#define ENCFILE_H_
#include<stddef.h>
#include"BinFile.h"

const size_t EF_OUTOFMEMORY = 0xFFFFFFFF; // memory is not suffient

class CEncodeFile : public CBinaryFile{
public:
  CEncodeFile();
  CEncodeFile(const char *pszPath, const char *pszFlags);
  CEncodeFile(const CEncodeFile &other);

  virtual ~CEncodeFile();

public:
  virtual size_t Read(void *buffer, size_t nSize);
  virtual size_t Write(const void *buffer,size_t nSize );

private:
  virtual void Encode(void *bufDest, const void * bufSrc, size_t nSize);
  virtual void Decode(void *buffer, size_t nSize);
};

#endif
