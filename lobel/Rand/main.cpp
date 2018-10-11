#include"Rand.h"
#include<iostream>
#include<stddef.h>

using namespace std;

int main(){
  CRand r;
  CRandTmpl<4,12341,3> s;
  int i;
  for(i=0;i<10;i++){
    cout << "(s,r) = (" << r.Rand() << "," << s.Rand() << ")" << endl;
  }
}
