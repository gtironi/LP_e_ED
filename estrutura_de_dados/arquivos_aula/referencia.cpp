#include <iostream>

using namespace std;

void troca(int &iValor1, int &iValor2);

int& trocaElemento(int iElemento, int arriVetor[]);

int main(){
    string strNome = "Yuri Saporito";
    int iValor = 42;
    int iValorFuturo = 666;

    cout << "Valor da string: " << strNome << " Endereço da String: " << &strNome <<endl;
    cout << "Valor do Inteiro: " << iValor << " Endereço do Inteiro: " << &iValor <<endl;
    
    cout << "==============================================" << endl;

    string& strrefNome = strNome; //cria referencia para variávl strNome
    int& irefValor = iValor;

    cout << "Valor Ref.string: " << strrefNome << " Endereço da Ref.String: " << &strrefNome <<endl;
    cout << "Valor Ref.Inteiro: " << irefValor << " Endereço do Ref.Inteiro: " << &irefValor <<endl;
    
    cout << "==============================================" << endl;

    strrefNome = "C. Camacho";
    irefValor = iValorFuturo;

    cout << "Valor da string: " << strNome << " Endereço da String: " << &strNome <<endl;
    cout << "Valor do Inteiro: " << iValor << " Endereço do Inteiro: " << &iValor <<endl;
    
    cout << "==============================================" << endl;
    
    int iValor1 = 2;
    int iValor2 = 12;

    cout << "Valor 1: " << iValor1 << endl;
    cout << "Valor 2: " << iValor2 << endl;

    troca(iValor1, iValor2);

    cout << "==============================================" << endl;

    cout << "Valor 1: " << iValor1 << endl;
    cout << "Valor 2: " << iValor2 << endl;

    cout << "==============================================" << endl;

    int arriVetor[5] = {0, 7, 13, 42, 666};
    cout <<"Vetor: " << endl;
    for (int i = 0; i < 5; i++){
        cout << "Vetor[" << i << "] = " << arriVetor[i] << endl;
    }

    arriVetor[3] = 11;

    trocaElemento(4, arriVetor) = 111;
    
    cout << "-----" << endl;

    cout<<"Vetor: " << endl;
    for (int i = 0; i < 5; i++){
        cout << "Vetor[" << i << "] = " << arriVetor[i] << endl;
    }

    return 0;
}

void troca(int& iValor1, int& iValor2){
    int iTemp = iValor1;
    iValor1 = iValor2;
    iValor2 = iTemp;
}

int& trocaElemento(int iElemento, int arriVetor[]){
    return arriVetor[iElemento];
}