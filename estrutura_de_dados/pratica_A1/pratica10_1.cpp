#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cout << "Digite os coeficientes da equacao quadratica (a, b, c): ";
    cin >> a >> b >> c;

    double discriminante = b * b - 4 * a * c;
    int numRaizes;

    if (discriminante < 0){
        numRaizes = 0;
    } else if (discriminante == 0) {
        numRaizes = 1;
    } else {
        numRaizes = 2;
    }

    switch (numRaizes) {
        case 0:
            cout << "A equacao nao possui raizes reais." << endl;
            break;
        case 1:
            cout << "A equacao possui uma raiz real." << endl;
            cout << "Raiz: x = " << -b / (2 * a) << endl;
            break;
        case 2:
            cout << "A equacao possui duas raizes reais distintas." << endl;
            cout << "Raiz 1: x1 = " << (-b + sqrt(discriminante)) / (2 * a) << endl;
            cout << "Raiz 2: x2 = " << (-b - sqrt(discriminante)) / (2 * a) << endl;
            break;
        default:
            cout << "Erro ao determinar o numero de raizes." << endl;
            break;
    }

    return 0;
}
