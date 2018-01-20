#include<cstdio>
#include<iostream>
#include<cstring>

#include"File.h"
#include"TextFile.h"
#include"BinFile.h"

bool Open(CFile &rfile, const char *pszFlags){
  char buffer[512];

  std::cout << "ファイル名を指定してください" << std::flush;
  std::cin >> buffer;

  return rfile.Open(buffer, pszFlags);
}

void Write(CTextFile &rtxt){
  char buffer[512];

  std::cout << "何を書き込みますか" << std::flush;
  std::cin >> buffer;
  rtxt.WriteString(buffer);
}

void Load(CFile &rbin){
  char buffer[512];
  int nRead;

  nRead = rbin.Read(buffer, numof(buffer));
  buffer[nRead] = 0;
  std::cout << buffer << std::endl;
}

int main(){
  CTextFile txt("Test.txt", "w");
  if(txt.IsValid() == false){
    return 0;
  }

  txt.WriteString("He sang, \"まったり　まったり　まったりな～♪\"");
  txt.Close();

  CBinaryFile bin("Test.txt", "r");
  if(bin.IsValid() == false){
    return 0;
  }

  const int READLENGTH = 16;
  char bufHex[READLENGTH * 3 + 1];
  char bufASCII[READLENGTH + 1];
  int nRead;

  do{
    nRead = bin.ReadAndDump(bufHex, bufASCII, READLENGTH);
    std::cout << bufHex << bufASCII << std::endl;
  }while(nRead == READLENGTH);

  return 0;
}
