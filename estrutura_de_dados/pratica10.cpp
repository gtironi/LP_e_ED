#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

typedef struct Aulas{
    string strPrimeira;
    string strSegunda;
    string strTerceira;
} Aulas;

typedef struct Grade{
    Aulas ptrSegunda;
    Aulas ptrTerca;
    Aulas ptrQuarta;
    Aulas ptrQuinta;
    Aulas ptrSexta;
} Grade;

void mostrarAulas(Aulas dia);


int main(){

    Grade GradeJoao;

    Aulas segunda;
    Aulas terca;
    Aulas quarta;
    Aulas quinta;
    Aulas sexta;

    segunda.strPrimeira = "Estrutura de Dados";
    segunda.strSegunda = "Probabilidade";
    segunda.strTerceira = "Calculo";

    terca.strPrimeira = "livre";
    terca.strSegunda = "ALN";
    terca.strTerceira = "TACD";

    quarta.strPrimeira = "Estrutura de Dados";
    quarta.strSegunda = "Probabilidade";
    quarta.strTerceira = "Calculo";

    quinta.strPrimeira = "livre";
    quinta.strSegunda = "ALN";
    quinta.strTerceira = "livre";

    sexta.strPrimeira = "livre";
    sexta.strSegunda = "Probabilidade";
    sexta.strTerceira = "TACD";

    GradeJoao.ptrSegunda = segunda;
    GradeJoao.ptrTerca = terca;
    GradeJoao.ptrQuarta = quarta;
    GradeJoao.ptrQuinta = quinta;
    GradeJoao.ptrSexta = sexta;

    int iDia;

    cout << "Escreva o número desejado (ex: segunda = 2): ";
    cin >> iDia;

    switch (iDia)
    {
    case 2:
        mostrarAulas(GradeJoao.ptrSegunda);
        break;
    case 3:
        mostrarAulas(GradeJoao.ptrTerca);
        break;
    case 4:
        mostrarAulas(GradeJoao.ptrQuarta);
        break;
    case 5:
        mostrarAulas(GradeJoao.ptrQuinta);
        break;
    case 6:
        mostrarAulas(GradeJoao.ptrSexta);
        break;
    default:
        cout << "Dia da semana não encontrado!" << endl;
        break;
    }

    return 0;
}

void mostrarAulas(Aulas dia){
    cout << "Aula das 7:30 às 9:10: " << dia.strPrimeira << endl;
    cout << "Aula das 9:20 às 11:00: " << dia.strSegunda << endl;
    cout << "Aula das 11:10 às 12:50: " << dia.strTerceira << endl;
    return;
}
