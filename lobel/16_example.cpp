#include<iostream>

class CA{
public:
  CA(){
    std::cout << "CA" << std::endl;
  }

  CA(int a){
    std::cout << "CA:" << a << std::endl;
  }

  ~CA(){
    std::cout << "~CA" << std::endl;
  }
};

class CB : public CA{
public:
  CB(){
    std::cout << "CB" << std::endl;
  }

  ~CB(){
    std::cout << "~CB" << std::endl;
  }
};

int main(){
  CB b;
  return 0;
}
