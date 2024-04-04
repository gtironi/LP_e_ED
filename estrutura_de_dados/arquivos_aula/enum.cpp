#include <iostream>

using namespace std;

int main(){
    enum Streaming {AppleTv, AmazonPrime, CrunchyRoll, DisneyPlus, NetFlix, Max};

    Streaming streamingSubscription = CrunchyRoll;

    switch (streamingSubscription){
        case AppleTv:
            cout << "Nunca usei... não tenho recursos para adquirir [" << streamingSubscription << "]" << endl;
        break;

        case CrunchyRoll:
            cout << "Muito bom... [" << streamingSubscription << "]" << endl;
        break;

        default:
            cout << "NADA" << endl;
    }
    
    cout << "==============================================" << endl;

    enum Meses {Janeiro = 1, Fevereiro, Marco, Abril, Maio};

    Meses mesProvas = Maio;

    cout << mesProvas << endl;

    enum Mes {JANEIRO = 10, FEVEREIRO, MARCO, ABRIL, MAIO};

    Mes Provas = MAIO;
    cout << Provas << endl;

    enum Semana {Segunda = 10, Terca = 1, Quarta = -3};

    Semana diaPalestra = Quarta;
    cout << diaPalestra << endl;
    return 0;
}