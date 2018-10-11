#include<stdio.h>
#include<string.h>
#include<dlfcn.h>
#include<stdlib.h>
#include<math.h>
struct Array{
  void *handle;
  int (*Sum)(void);		/* 合計 */
  void (*Show)(void);		/* 出力 */
  void (*SetSize)(int);		/* Sizeのアクセッサ */
  void (*SetArray)(int, int);	/* Arrayのアクセッサ */
  int (*GetSize)(void);		/* Sizeのアクセッサ */
  int (*GetArray)(int);		/* Arrayのアクセッサ */
};

void error(void){
  char *er = dlerror();
  if(er != NULL){
    fprintf(stderr, "%s\n", er);
    exit(1);
  }
}
struct Array *new_Array(int size){
  struct Array *array = malloc(sizeof(struct Array));
  
  void *handle = dlopen("libArray.so", RTLD_NOW | RTLD_DEEPBIND);
  error();

  if(handle != NULL){
    void (*Array)(int) = (void (*)(int))dlsym(handle, "Array");
    error();
    
    array -> Sum = (int (*)(void))dlsym(handle, "Sum");
    error();
    
    array -> Show = (void (*)(void))dlsym(handle, "Show");
    error();
    
    array -> SetArray = (void (*)(int, int))dlsym(handle, "SetArray");
    error();

    array -> GetSize = (int (*)(void))dlsym(handle, "GetSize");
    error();

    array -> GetArray = (int (*)(int))dlsym(handle, "GetArray");
    error();

    dlclose(handle);
    Array(size);
  }
  return array;
}

void del_Array(struct Array *array){
  dlclose(array -> handle);
}

int main(){
  struct Array *a = malloc(sizeof(struct Array));
  struct Array *b = malloc(sizeof(struct Array));

  int n;
  int i;
  char str[32];
  printf("要素数1 : ");
  scanf("%d", &n);
  a = new_Array(n);
  sprintf(str, "a[%%%dd] = ", (int)log10(a -> GetSize() - 1) + 1);
  for(i = 0; i < n; i++){
    int n;
    printf(str, i);
    scanf("%d", &n);
    a -> SetArray(i, n);
  }
  
  printf("要素数2 : ");
  scanf("%d", &n);
  b = new_Array(n);
  sprintf(str, "b[%%%dd] = ", (int)log10(b -> GetSize() - 1) + 1);
  for(i = 0; i < n; i++){
    int n;
    printf(str, i);
    scanf("%d", &n);
    b -> SetArray(i, n);
  }

  printf("aの合計 : %d\n", a -> Sum());
  printf("bの合計 : %d\n", b -> Sum());
  return 0;
}
