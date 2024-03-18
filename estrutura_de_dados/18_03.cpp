#include <iostream>

using std::cout;
using std::string;
using std::endl;

void troca(int&, int&);
int& trocaElemento(int, int[]);

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

    cout << "Valor da string: " << strrefNome << ". Endereço da string: " << &strrefNome << endl;
    cout << "Valor do inteiro: " << irefValor << ". Endereço do inteiro: " << &irefValor << endl;
    cout << "===================================================" << endl;

    strrefNome = "C. Camacho";
    irefValor = 111;

    cout << "Valor da string: " << strrefNome << ". Endereço da string: " << &strrefNome << endl;
    cout << "Valor do inteiro: " << irefValor << ". Endereço do inteiro: " << &irefValor << endl;
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

    int arriVetor[5] = {0, 7, 13, 42, 666};

    for (int i = 0; i < 5; i++)
    {
        cout << "Vetor[" << i << "] = " << arriVetor[i] << endl;
    }

    cout << "-----" << endl;

    trocaElemento(3, arriVetor) = 111;

    for (int i = 0; i < 5; i++)
    {
        cout << "Vetor[" << i << "] = " << arriVetor[i] << endl;
    }

    return 0;
}

void troca(int& irefValor1, int& irefValor2)
{
    int iTemp = irefValor1;
    irefValor1 = irefValor2;
    irefValor2 = iTemp;
}

int& trocaElemento(int iElemento, int arriVector[])
{
    return arriVector[iElemento];
}
