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
