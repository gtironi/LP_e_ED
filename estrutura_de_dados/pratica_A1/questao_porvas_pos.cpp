#include <iostream>

using std::cout;
using std::endl;

//structs
typedef struct Node{
    int iData;
    Node* ptrNext;
} Node;

typedef struct Queue{
    Node* ptrHead;
    Node* ptrTail;
} Queue;

//funções
Node* newNode(int);
Queue* newQueue();
void enQueue(Queue* const, int);
void showElements(Queue* const);
void deAllQueue(Queue* const);
void deSpecifQueue(Queue* const, int);

//main
int main(){
    Queue* queue = newQueue();

    enQueue(queue, 1);

    enQueue(queue, 1);

    enQueue(queue, 1);

    enQueue(queue, 2);

    enQueue(queue, 3);

    enQueue(queue, 1);

    enQueue(queue, 4);

    enQueue(queue, 5);

    enQueue(queue, 1);

    showElements(queue);

    cout << "----------------------" << endl;

    deSpecifQueue(queue, 1);

    showElements(queue);





    return 0;
}

Node* newNode(int iValue){
    Node* temp = (Node*) malloc(sizeof(Node));

    temp -> iData = iValue;
    temp -> ptrNext = nullptr;

    return temp;
}

Queue* newQueue(){
    Queue* temp = (Queue*) malloc(sizeof(Node));

    temp -> ptrHead = nullptr;
    temp -> ptrTail = nullptr;

    return temp;
}

void enQueue(Queue* const queue, int iValue){
    Node* temp = newNode(iValue);

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

void showElements(Queue* const queue){

    if(queue == nullptr || queue -> ptrHead == nullptr){
        cout << "A fila está vazia!" << endl;
        return;
    }

    Node* current = queue -> ptrHead;

    int iCounter = 1;

    while(current != nullptr){
        cout << "O elemento " << iCounter << " da fila é: " << current -> iData << endl;
        current = current -> ptrNext;
        iCounter++;
    }

    return;
}

void deAllQueue(Queue* const queue){
    if(queue == nullptr || queue -> ptrHead == nullptr){
        cout << "A fila está vazia!" << endl;
        return;
    }
    Node* current = queue -> ptrHead;
    Node* previous = nullptr;

    queue -> ptrHead = nullptr;
    queue -> ptrTail = nullptr;

    while(current != nullptr){
        previous = current;
        current = current -> ptrNext;
        free(previous);
    }

    return;
}

void deSpecifQueue(Queue* const queue, int iValue){
    if(queue == nullptr || queue -> ptrHead == nullptr){
        cout << "A fila está vazia!" << endl;
        return;
    }

    Node* current = queue -> ptrHead;

    while(queue -> ptrHead != nullptr && queue -> ptrHead -> iData == iValue){
        queue -> ptrHead = queue -> ptrHead -> ptrNext;
        free(current);
        current =  queue -> ptrHead;
    }

    Node* previous = nullptr;
    Node* deletar;

    while(current != nullptr){

        if(current -> iData == iValue){
            deletar = current;
            previous -> ptrNext = current -> ptrNext;
            previous = current;
            current = current -> ptrNext;
            free(deletar);
        }
        else{
            previous = current;
            current = current -> ptrNext;
        }
    }

    return;
}