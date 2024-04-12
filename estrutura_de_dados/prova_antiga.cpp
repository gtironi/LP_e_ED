#include <iostream>

using std::cout;
using std::endl;
using std::string;

//structs
typedef struct Aluno{
    int sMatricula;
    Aluno* ptrNext;

} Aluno;

typedef struct LinkedList{
    Aluno* ptrHead;

} LinkedList;

//funções
Aluno* newAluno(int sMatricula);
LinkedList* newLinkedList();
void addLinkedList(LinkedList* const, int);
void showElements(LinkedList* const);
void dellLinkedList(LinkedList* const, int);
void switchFirstLast(LinkedList* const);
LinkedList* interLinkedLists(LinkedList* const, LinkedList* const);
int cicleSize(LinkedList* const);

//main

int main(){

    cout << "Questão 1 ----------------------------------------------" << endl;

    LinkedList* linkedlist = nullptr;

    addLinkedList(linkedlist, 102938745);

    showElements(linkedlist);

    linkedlist = newLinkedList();

    showElements(linkedlist);

    addLinkedList(linkedlist, 102938745);

    showElements(linkedlist);

    addLinkedList(linkedlist, 345938745);

    addLinkedList(linkedlist, 567938745);

    addLinkedList(linkedlist, 789038745);

    addLinkedList(linkedlist, 169038745);

    addLinkedList(linkedlist, 289038745);

    addLinkedList(linkedlist, 489560745);

    addLinkedList(linkedlist, 670560745);

    addLinkedList(linkedlist, 891456745);

    showElements(linkedlist);

    addLinkedList(linkedlist, 965876745);

    showElements(linkedlist);
    
    cout << "--------------------------------------------------------" << endl;

    cout << "Questão 2 ----------------------------------------------" << endl;

    LinkedList* linkedlist1 = nullptr;

    dellLinkedList(linkedlist1, 289038745);

    linkedlist1 = newLinkedList();

    dellLinkedList(linkedlist1, 289038745);

    addLinkedList(linkedlist1, 289038745);

    addLinkedList(linkedlist1, 345938745);

    addLinkedList(linkedlist1, 567938745);

    addLinkedList(linkedlist1, 789038745);

    addLinkedList(linkedlist1, 169038745);

    showElements(linkedlist1);

    dellLinkedList(linkedlist1, 289038745);

    showElements(linkedlist1);

    dellLinkedList(linkedlist1, 789038745);

    showElements(linkedlist1);

    dellLinkedList(linkedlist1, 567938874);

    cout << "--------------------------------------------------------" << endl;

    cout << "Questão 3 ----------------------------------------------" << endl;

    LinkedList* linkedlist2 = nullptr;

    switchFirstLast(linkedlist2);

    linkedlist2 = newLinkedList();

    switchFirstLast(linkedlist2);

    showElements(linkedlist);

    switchFirstLast(linkedlist);

    showElements(linkedlist);

    showElements(linkedlist1);

    switchFirstLast(linkedlist1);

    showElements(linkedlist1);

    cout << "--------------------------------------------------------" << endl;

    cout << "Questão 4 ----------------------------------------------" << endl;

    addLinkedList(linkedlist1, 576537745);
    
    showElements(linkedlist);

    showElements(linkedlist1);

    LinkedList* interLinkedList = interLinkedLists(linkedlist, linkedlist1);

    showElements(interLinkedList);

    cout << "--------------------------------------------------------" << endl;
    
    cout << "Questão 5 ----------------------------------------------" << endl;

    int iTam = cicleSize(linkedlist);

    addLinkedList(linkedlist, 789076745);

    iTam = cicleSize(linkedlist);

    LinkedList* cicledLinkedList = nullptr;

    int iTamCicle = cicleSize(cicledLinkedList);

    cicledLinkedList = newLinkedList();

    iTamCicle = cicleSize(cicledLinkedList);

    addLinkedList(cicledLinkedList, 1);

    addLinkedList(cicledLinkedList, 2);

    addLinkedList(cicledLinkedList, 3);

    addLinkedList(cicledLinkedList, 4);

    addLinkedList(cicledLinkedList, 5);

    cicledLinkedList -> ptrHead -> ptrNext -> ptrNext -> ptrNext -> ptrNext -> ptrNext = cicledLinkedList -> ptrHead -> ptrNext -> ptrNext;

    iTamCicle = cicleSize(cicledLinkedList);

    cout << iTamCicle << endl;

    cout << "--------------------------------------------------------" << endl;



    return 0;
}

//questão 1 ---------------------------------------------------------
Aluno* newAluno(int sMatricula_){
    Aluno* temp = (Aluno*) malloc(sizeof(Aluno));

    temp -> sMatricula = sMatricula_;

    temp -> ptrNext = nullptr;

    return temp;
}

LinkedList* newLinkedList(){
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));

    temp -> ptrHead = nullptr;

    return temp;
}

void addLinkedList(LinkedList* const linkedList, int sMatricula){
    if(linkedList == nullptr){
        cout << "A lista não existe!" << endl;
        return;
    }

    Aluno* temp = newAluno(sMatricula);

    if(linkedList -> ptrHead == nullptr){
        linkedList -> ptrHead = temp;
        return;
    }

    Aluno* lastAluno = linkedList -> ptrHead;

    while(lastAluno -> ptrNext != nullptr){
        lastAluno = lastAluno -> ptrNext;
    }

    lastAluno -> ptrNext = temp;

    return;
}

void showElements(LinkedList* const linkedList){
    if(linkedList == nullptr){
        cout << "A lista não existe!" << endl;
        return;
    }
    if(linkedList -> ptrHead == nullptr){
        cout << "A lista é vazia!" << endl;
        return;
    }

    Aluno* current = linkedList -> ptrHead;

    cout << "[";

    while(current -> ptrNext != nullptr){
        cout << current -> sMatricula << ", ";
        current = current -> ptrNext;
    }

    cout << current -> sMatricula << "]" << endl;

    return;
}

//questão 2 ---------------------------------------------------------
void dellLinkedList(LinkedList* const linkedList, int sMatriculaRemover){
    if(linkedList == nullptr){
        cout << "A lista não existe!" << endl;
        return;
    }
    if(linkedList -> ptrHead == nullptr){
        cout << "A lista é vazia!" << endl;
        return;
    }

    Aluno* current = linkedList -> ptrHead;
    Aluno* previous = nullptr;

    if(current -> sMatricula == sMatriculaRemover){
        linkedList -> ptrHead = current -> ptrNext;
        free(current);
        return;
    }

    while(current != nullptr && current -> sMatricula != sMatriculaRemover){
        previous = current;
        current = current -> ptrNext;
    }

    if (current == nullptr){
        cout << "Elemento não encontrado!" << endl;
        return;
    }

    previous -> ptrNext = current -> ptrNext;

    free(current);
    return;
}

//questão 3 ---------------------------------------------------------
void switchFirstLast(LinkedList* const linkedList){
    if(linkedList == nullptr){
        cout << "A lista não existe!" << endl;
        return;
    }
    if(linkedList -> ptrHead == nullptr){
        cout << "A lista é vazia!" << endl;
        return;
    }

    if(linkedList -> ptrHead -> ptrNext == nullptr){
        return;
    }

    Aluno* firstAluno = linkedList -> ptrHead;
    Aluno* lastAluno = linkedList -> ptrHead;
    
    Aluno* lastLastAluno = nullptr;

    while(lastAluno -> ptrNext != nullptr){
        lastLastAluno = lastAluno;
        lastAluno = lastAluno -> ptrNext;
    }

    lastAluno -> ptrNext = firstAluno -> ptrNext;

    firstAluno -> ptrNext = nullptr;

    lastLastAluno -> ptrNext = firstAluno;

    linkedList -> ptrHead = lastAluno;

    return;
}

//questão 4 ---------------------------------------------------------
LinkedList* interLinkedLists(LinkedList* const linkedList1, LinkedList* const linkedList2){
    LinkedList* linkedListInter = nullptr;
    
    if(linkedList1 == nullptr || linkedList2 == nullptr){
        cout << "Uma das listas não existe!" << endl;
        return linkedListInter;
    }
    if(linkedList1 -> ptrHead == nullptr || linkedList2 -> ptrHead == nullptr){
        cout << "Uma das lista é vazia!" << endl;
        return linkedListInter;
    }

    linkedListInter = newLinkedList();

    Aluno* alunoLista1 = linkedList1 -> ptrHead;
    Aluno* alunoLista2 = linkedList2 -> ptrHead;

    while(alunoLista1 != nullptr){

        alunoLista2 = linkedList2 -> ptrHead;

        while(alunoLista2 != nullptr && alunoLista2 -> sMatricula != alunoLista1 -> sMatricula){
            alunoLista2 = alunoLista2 -> ptrNext;
        }

        if(alunoLista2 != nullptr){
            if (alunoLista2 -> sMatricula == alunoLista1 -> sMatricula){

            addLinkedList(linkedListInter, alunoLista1 -> sMatricula);
            }  
        }

        alunoLista1 = alunoLista1 -> ptrNext;
    }

    return linkedListInter;
}

//questão 5 ---------------------------------------------------------

int cicleSize(LinkedList* const linkedList){

    if(linkedList == nullptr){
        cout << "A lista não existe!" << endl;
        return -1;
    }
    if(linkedList -> ptrHead == nullptr){
        cout << "A lista é vazia!" << endl;
        return -1;
    }

    int iCicleSize = 1;

    Aluno* pulaUm = linkedList -> ptrHead -> ptrNext;

    Aluno* pulaDois = linkedList -> ptrHead -> ptrNext -> ptrNext;

    while (pulaDois != nullptr && pulaUm -> sMatricula != pulaDois -> sMatricula){

        pulaUm = pulaUm -> ptrNext;
        if(pulaDois -> ptrNext != nullptr){
            pulaDois = pulaDois -> ptrNext -> ptrNext;
        }
        else{
            pulaDois = nullptr;
        }
        iCicleSize++;
    }

    if(pulaDois == nullptr){
        cout << "Não há ciclo!" << endl;
        return 0;
    }

    cout << "Há um ciclo de tamanho: " << iCicleSize << endl;

    return iCicleSize;
}