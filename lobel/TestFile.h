#include<iostream>
#include<string.h>
#include"BinFile.h"
#include"EncFile.h"

static const char szPath[] = "Test.dat";

bool Write(CFile &rfile){
  char buffer[512];

  std::cout << "ファイルに書き込むデータを入力してください" << std::endl;
  std::cin >> buffer;

  if(rfile.Open(szPath, "w") == false){
    return false;
  }

  if(rfile.Write(buffer, strlen(buffer)) == EF_OUTOFMEMORY){
    return false;
  }

  rfile.Close();

  return true;
}

bool Read(CBinaryFile &rbin){
  const int PER_LINE = 16;
  char bufHex[PER_LINE * 3 + 1];
  char bufASCII[PER_LINE + 1];
  int nRead;

  if(rbin.Open(szPath, "r") == false){
    return false;
  }

  do{
    nRead = rbin.ReadAndDump(bufHex, bufASCII, PER_LINE);
    std::cout << bufHex << "| " << bufASCII << std::endl;
  }while(nRead == PER_LINE);

  rbin.Close();

  return true;
}


int main(){
  CBinaryFile bin;
  CEncodeFile enc;

  puts("暗号化して書き込みます");
  if(Write(enc) == false){
    return 0;
  }

  puts("復号せずに読み込みます");
  if(Read(bin) == false){
    return 0;
  }

  puts("復号して読み込みます");
  if(Read(enc) == false){
    return 0;
  }

  return 0;
}
