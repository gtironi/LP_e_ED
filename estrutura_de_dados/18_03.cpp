#include <iostream>

using std::cout;
using std::string;
using std::endl;

void troca(int, int);

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

    int iNum1 = 7;
    int iNum2 = 42;

    cout << "iNum1: " << iNum1 << endl;
    cout << "iNum2: " << iNum2 << endl;
    cout << "===================================================" << endl;

    troca(iNum1, iNum2);

    cout << "iNum1: " << iNum1 << endl;
    cout << "iNum2: " << iNum2 << endl;
    cout << "===================================================" << endl;

    return 0;
}

void troca(int iValor1, int iValor2)
{

    int iTemp = iValor1;
    iValor1 = iValor2;
    iValor2 = iTemp;
}