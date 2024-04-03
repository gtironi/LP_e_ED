#include <iostream>

using std::cout;
using std::string;
using std::endl;

int main()
{
    enum Streaming {AppleTV, AmazonPrime, CrunchyRoll, DisneyPlus, Netflix};

    Streaming streamingSubscription = CrunchyRoll;

    switch (streamingSubscription)
    {
        case AppleTV:
            cout << "Nunca usei... não sei como é... [" << streamingSubscription << "]" << endl;
            break;
        case CrunchyRoll:
            cout << "Muito bom... [" << streamingSubscription << "]" << endl;
            break;
        default:
            cout << "NADA" << endl;
    }

    cout << "===============================" << endl;

    enum Meses {Janeiro = 1, Fevereiro, Marco, Abril, Maio};

    Meses mesProvas = Maio;

    cout << mesProvas << endl;

    enum Semana {Segunda = 10, Terca = 1, Quarta = -3};

    Semana diaPalestra = Quarta;
    cout << diaPalestra << endl;

    return 0;
}