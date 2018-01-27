#ifndef ENCFILE_H_
#define ENCFILE_H_
#include<stddef.h>
#include"BinFile.h"

const size_t EF_OUTOBMEMORY = 0xFFFFFFFF; // memory is not suffient

class CEncodeFile : public CBinaryFile{
public:
  CEncodeFile();
  CEncodeFile(const void *buffer, size_t nSize);

private:
  virtual void Encode(void *bufDest, const void * bufSrc, size_t nSize);
  virtual void Decode(void *buffer, size_t nSize);
};

#endif
