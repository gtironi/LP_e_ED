#include <iostream>

using std::cout;
using std::endl;

//structs
typedef struct Carro{
    float fKmRodado;
    int iAno;
} Carro;

typedef struct Node{
    Carro* ptrCarro;
    Node* ptrNext;
} Node;

typedef struct Queue{
    Node* ptrHead;
    Node* ptrTail;
} Queue;

//funções
Carro* newCarro(int, float);
Node* newNode(int, float);
Queue* newQueue();
void enQueue(Queue* const, int, float);
void deQueue(Queue* const);
void showFirstElement(Queue* const);
void showLastElement(Queue* const);
void showElements(Queue* const);

//main
int main(){


    Queue* queue = nullptr;

    enQueue(queue, 2013, 100.8);

    queue = newQueue();

    enQueue(queue, 2013, 100.8);

    enQueue(queue, 2015, 165.2);

    showLastElement(queue);

    enQueue(queue, 2017, 53.7);

    showFirstElement(queue);

    showLastElement(queue);

    showElements(queue);

    deQueue(queue);

    showElements(queue);

    deQueue(queue);

    deQueue(queue);

    showElements(queue);

    deQueue(queue);

    return 0;
}

//definição de funções

Carro* newCarro(int iValue, float fKilometragem){
    Carro* temp = (Carro*) malloc(sizeof(Carro));

    temp -> fKmRodado = fKilometragem;
    temp -> iAno = iValue;

    return temp;
}

Node* newNode(int iValue, float fKilometragem){
    Node* temp = (Node*) malloc(sizeof(Node));

    temp -> ptrCarro = newCarro(iValue, fKilometragem);
    temp -> ptrNext = nullptr;

    return temp;
}

Queue* newQueue(){
    Queue* temp = (Queue*) malloc(sizeof(Node));

    temp -> ptrHead = nullptr;
    temp -> ptrTail = nullptr;

    return temp;
}

void enQueue(Queue* const queue, int iValue, float fKilometragem){
    Node* temp = newNode(iValue, fKilometragem);

    if(queue == nullptr){
        cout << "A fila não existe!" << endl;
        return;
    }
    if(queue -> ptrHead == nullptr){
        queue -> ptrHead = temp;
        queue -> ptrTail = temp;
        return;
    }

    queue -> ptrTail -> ptrNext = temp;
    queue -> ptrTail = temp;

    return;
}

void showFirstElement(Queue* const queue){

    if(queue == nullptr || queue -> ptrHead == nullptr){
        cout << "A fila está vazia!" << endl;
        return;
    }

    cout << "Primeiro elemento da fila: " << queue -> ptrHead -> ptrCarro -> iAno << " (ano), " << queue -> ptrHead -> ptrCarro -> fKmRodado << " (KM)" << endl;

    return;
}

void showLastElement(Queue* const queue){

    if(queue == nullptr || queue -> ptrHead == nullptr){
        cout << "A fila está vazia!" << endl;
        return;
    }

    cout << "Último elemento da fila: " << queue -> ptrTail -> ptrCarro -> iAno << " (ano), " << queue -> ptrTail -> ptrCarro -> fKmRodado << " (KM)" << endl;

    return;
}

void showElements(Queue* const queue){

    if(queue == nullptr || queue -> ptrHead == nullptr){
        cout << "A fila está vazia!" << endl;
        return;
    }

    Node* current = queue -> ptrHead;

    int iCounter = 1;

    while(current != nullptr){
        cout << "O elemento " << iCounter << " da fila é: " << current -> ptrCarro -> iAno << " (ano), " << current -> ptrCarro -> fKmRodado << " (KM)" << endl;
        current = current -> ptrNext;
        iCounter++;
    }

    return;
}

void deQueue(Queue* const queue){

    if(queue == nullptr || queue -> ptrHead == nullptr){
        cout << "A fila está vazia!" << endl;
        return;
    }

    Node* temp = queue -> ptrHead;

    cout << "Deletando o elemento: " << temp -> ptrCarro -> iAno << " (ano), " << temp -> ptrCarro -> fKmRodado << " (KM)..." << endl;

    queue -> ptrHead = temp -> ptrNext;

    free(temp -> ptrCarro);
    free(temp);

    return;
}