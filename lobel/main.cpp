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

void Viss(int num){
  std::cout << "Viss : " << num << std::endl;
}

int main(){
  CBinaryFile *pbin;

  Viss(1);

  pbin = new CBinaryFile("Test.txt","r");
  if(pbin == NULL){
    return 0;
  }

  Viss(2);
  delete pbin;

  Viss(3);

  return 0;
}
