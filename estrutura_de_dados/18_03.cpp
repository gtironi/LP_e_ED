#include <iostream>

using std::cout;
using std::string;
using std::endl;

int main()
{
    string strNome = "Yuri Saporito";
    int iValor = 42;
    int iValorFuturo = 666;

    cout << "Valor da string: " << strNome << ". Endereço da string: " << &strNome << endl;
    cout << "Valor do inteiro: " << iValor << ". Endereço do inteiro: " << &iValor << endl;
    cout << "===================================================" << endl;

    string& strrefNome = strNome;
    int& irefValor = iValor;

    cout << "Valor da string: " << strNome << ". Endereço da string: " << &strNome << endl;
    cout << "Valor do inteiro: " << iValor << ". Endereço do inteiro: " << &iValor << endl;
    cout << "===================================================" << endl;

    strrefNome = "C. Camacho";
    irefValor = 111;

    cout << "Valor da string: " << strNome << ". Endereço da string: " << &strNome << endl;
    cout << "Valor do inteiro: " << iValor << ". Endereço do inteiro: " << &iValor << endl;
    cout << "===================================================" << endl;

    return 0;
}