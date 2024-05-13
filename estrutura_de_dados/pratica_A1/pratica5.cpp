#include <iostream>

//definindo as estruturas
typedef struct Node{
    int iData;
    Node* ptrNext;
} Node;

typedef struct Queue{
    Node* ptrHead;
    Node* ptrTail;
} Queue;

//definindo a chamada das funções
Node* newNode(int);
Queue* newQueue();
void enQueue(Queue* const, int);
void deQueue(Queue* const);
void showFirstElement(Queue* const);
void showLastElement(Queue* const);
void showElements(Queue* const);


// executando o codigo
int main(){

    Queue* queue = newQueue();
    showFirstElement(queue);
    showLastElement(queue);

    std::cout << "==========================================" << std::endl;

    // adicionando elementos na fila
    enQueue(queue, 0);
    showFirstElement(queue);
    showLastElement(queue);
    
    std::cout << "==========================================" << std::endl;

    enQueue(queue, 10);
    showFirstElement(queue);
    showLastElement(queue);

    std::cout << "==========================================" << std::endl;

    enQueue(queue, 11);
    enQueue(queue, 12);
    enQueue(queue, 13);
    enQueue(queue, 14);
    enQueue(queue, 15);
    showElements(queue);

    std::cout << "==========================================" << std::endl;

    Queue* queue2 = newQueue();

    deQueue(queue);

    showElements(queue);

    deQueue(queue2);

    std::cout << "==========================================" << std::endl;

    return 0;
}

//definindo as funções
Node* newNode(int iValue){
    Node* ptrTemp = (Node*) malloc(sizeof(Node));

    ptrTemp -> iData = iValue;
    ptrTemp -> ptrNext = nullptr;

    return ptrTemp;
}

Queue* newQueue(){
    Queue* ptrTemp = (Queue*) malloc(sizeof(Queue));

    ptrTemp -> ptrHead = nullptr;
    ptrTemp ->  ptrTail = nullptr;

    return ptrTemp;
}

void enQueue(Queue* const ptrQueue, int iValue){

    Node* ptrTemp = newNode(iValue);

    if(ptrQueue -> ptrHead == nullptr){
        ptrQueue -> ptrHead = ptrTemp;
        ptrQueue ->  ptrTail = ptrTemp;
    }
    else{
        ptrQueue -> ptrTail -> ptrNext = ptrTemp;
        ptrQueue ->  ptrTail = ptrTemp;
    }
    return;
}

void deQueue(Queue* const ptrQueue){

    Node* ptrDeleteNode = ptrQueue -> ptrHead;

    std::cout << "Deletando o elemento " << ptrDeleteNode -> iData << "..." << std::endl;

    ptrQueue ->  ptrHead = ptrDeleteNode -> ptrNext;

    free(ptrDeleteNode);

    return;
}

void showFirstElement(Queue* const ptrQueue){
    std::cout << "O primeiro elemento é: " << ((ptrQueue -> ptrHead != nullptr)? ptrQueue -> ptrHead -> iData : -1) << std::endl;
    return;
}

void showLastElement(Queue* const ptrQueue){
    std::cout << "O último elemento é: " << ((ptrQueue -> ptrTail != nullptr)? ptrQueue -> ptrTail -> iData : -1) << std::endl;
    return;
}

void showElements(Queue* const ptrQueue){
    Node* current = ptrQueue -> ptrHead;

    if(current == nullptr){
        std::cout << "Fila vazia" << std::endl;
        return;
    }

    int iCounter  = 1;
    while (current != nullptr){
        std::cout << "O elemento " << iCounter << " da fila é: " << current -> iData << std::endl;
        current = current -> ptrNext;
        iCounter++;
    }

    return;
}