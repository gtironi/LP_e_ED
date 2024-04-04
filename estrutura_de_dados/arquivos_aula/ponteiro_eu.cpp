#include <iostream>

using namespace std;

void doub(int*); //recebe um ponteiro

int main()
{
  int a;
  int b;
  int c;
  int *ptr = nullptr;  // declara um ponteiro para um inteiro
             // um ponteiro para uma variável do tipo inteiro
  a = 90;
  b = 2;
  c = 3;
  ptr = &a; // define para onde o ponteiro aponta

  cout << "Valor de ptr (sem asterisco): " << ptr << ", Conteúdo de ptr (com asterisco): " << *ptr <<endl;
  cout << "B: " << b << ", C: " << c <<endl;

  a = 40;
  cout << "Valor de ptr (sem asterisco): " << ptr << ", Conteúdo de ptr (com asterisco): " << *ptr <<endl;

  doub(ptr);
  cout <<"Valor de A: " << a << endl;
  
  return 0;
}

void doub(int *ptr_num)
{
    (*ptr_num) = (*ptr_num) * 2;
}