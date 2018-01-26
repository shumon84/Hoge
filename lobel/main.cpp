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

void Read(CFile *pfile){
  if(pfile -> Open("Test.txt", "r") == false){
    return;
  }

  char buffer[512];

  pfile -> Read(buffer, sizeof(buffer));
  std::cout << buffer << std::endl;
  pfile -> Close();
}

void Write(CFile *pfile){
  if(pfile -> Open("Test.txt", "w") == false){
    return;
  }
  char buffer[] = "食すな危険";

  pfile -> Write(buffer, sizeof(buffer));
  pfile -> Close();
}

int main(){
  CFile *pfile;

  puts("CBinaryFileのインスタンス生成開始");
  pfile = new CBinaryFile;
  puts("CBinaryFileのインスタンス生成終了");

  if(pfile == NULL){
    return 0;
  }

  puts("Write開始");
  Write(pfile);
  puts("Write終了");
  puts("CBinaryFileのインスタンス破棄開始");
  delete pfile;
  puts("CBinaryFileのインスタンス破棄終了");

  puts("CTextFileのインスタンス生成開始");
  pfile = new CTextFile;
  puts("CTextFileのインスタンス生成開始");

  if(pfile == NULL){
    return 0;
  }

  puts("Read開始");
  Read(pfile);
  puts("Read終了");

  puts("CTextFileのインスタンス破棄開始");
  delete pfile;
  puts("CTextFileのインスタンス破棄終了");

  return 0;
}
