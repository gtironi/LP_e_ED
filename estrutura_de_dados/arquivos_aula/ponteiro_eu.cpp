#include <stdio.h>
#include <iostream>

using namespace std;

void doub(int*);

int main()
{
  int a;
  int b;
  int c;
  int *ptr;  // declara um ponteiro para um inteiro
             // um ponteiro para uma variável do tipo inteiro
  a = 90;
  b = 2;
  c = 3;
  ptr = &a;

  cout << "Valor de ptr: " << ptr << ", Conteúdo de ptr: " << *ptr <<endl;
  cout << "B: " << b << ", C: " << c <<endl;

  a = 40;
  cout << "Valor de ptr: " << ptr << ", Conteúdo de ptr: " << *ptr <<endl;

  doub(ptr);
  cout <<"Valor de A: " << a << endl;
  
  return 0;
}

void doub(int *ptr_num)
{
    (*ptr_num) = (*ptr_num) * 2;
}