#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::cin;
using std::endl;

float calcula_IMC(float fAltura, float fMassa) 
{
    float fIMC = fMassa / (fAltura * fAltura); 

    return fIMC; //Retorna o IMC
}

string verifica_IMC(float fIMC) 
{
    string cIndice;

    if (fIMC < 17) //Verifica em qual categoria o IMC se enquadra
    {
        cIndice = "Muito abaixo do peso";
    }
    else if (fIMC >= 17 && fIMC < 18.5)
    {
        cIndice = "Abaixo do peso";
    }
    else if (fIMC >= 18.5 && fIMC < 25)
    {
        cIndice = "Peso normal";
    }
    else if (fIMC >= 25 && fIMC < 30)
    {
        cIndice = "Acima do peso";
    }
    else if (fIMC >= 30 && fIMC < 35)
    {
        cIndice = "Obesidade";
    }
    else if (fIMC >= 35 && fIMC < 40)
    {
        cIndice = "Obesidade severa";
    }
    else
    {
        cIndice = "Obesidade mórbida";
    }

    return cIndice;
}

int main()
{
    float fAltura, fMassa;
    cout << "Digite sua altura (em metros): "; //Pede para o usuário informar sua altura
    cin >> fAltura;

    cout << "Digite seu peso (em quilogramas): "; //Pede para o usuário informar seu peso
    cin >> fMassa;

    float fIMC = calcula_IMC(fAltura, fMassa); //Calcula o IMC

    cout << "Seu IMC é: " << fIMC << ". Esse valor se enquadra como: " << verifica_IMC(fIMC) << endl; //Retorna o IMC e o classificação para o usuário

    return 0;
}

