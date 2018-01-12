#include<stdlib.h>
#include<stdio.h>
int size;
int *ary;

void Array(int n){
  size=n;
  ary=calloc(size, sizeof(int));
}

int Sum(void){
  int i;
  int sum=0;
  for(i=0;i<size;i++){
    sum+=ary[i];
  }
  return sum;
}

void Show(void){
  int i;
  for(i=0;i<size;i++){
    printf("ary[%d] = %d\n",i,ary[i]);
  }
}
void _Array(void){
  int i;
  for(i=size;i>0;i--){
    free(ary+(i-1));
  }
}

void SetArray(int index,int n){
  if(index < size){
    ary[index] = n;
  }
}

int GetSize(void){
  return size;
}

int GetArray(int index){
  if(index < size){    
    return ary[index];
  }
  else{
    return 0;
  }
}
