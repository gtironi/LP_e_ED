#include <iostream>

using std::cout;
using std::string;
using std::cin;
using std::endl;

int main()
{
    int iAno;
    cout << "Digite o ano a ser verificado: "; //Pede para o usuário informar um ano
    cin >> iAno;

    if ((iAno % 4 == 0 && iAno % 100 != 0) || iAno % 400 == 0) //Verifica se é bissexto
    {
        cout << "O ano de " << iAno << " é bissexto" << endl;
    }
    else
    {
        cout << "O ano de " << iAno << " não é bissexto" << endl; 
    }

    return 0;
}