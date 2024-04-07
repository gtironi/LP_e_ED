#include <iostream>

typedef struct Node{
    int iData;
    Node* ptrNext;
} Node;

typedef struct Queue{
    Node* head;
    Node* tail;
} Queue;

Node* newNode(int iValue);
Queue* newQueue();
void enQueue(Queue* const queue, int iValue);
void deQueue(Queue* const queue);
void showFirstElement(Queue* const queue);
void showLastElement(Queue* const queue);
void showElements(Queue* const queue);

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

Node* newNode(int iValue){
    Node* temp = (Node*) malloc(sizeof(Node));

    temp->iData = iValue;
    temp->ptrNext = nullptr;

    return temp;
}

Queue* newQueue(){
    Queue* temp = (Queue*) malloc(sizeof(Queue));

    temp->head = nullptr;
    temp->tail = nullptr;

    return temp;
}

void enQueue(Queue* const queue, int iValue){
    Node* temp = newNode(iValue);

    if(queue->head == nullptr){
        queue->head = temp;
        queue->tail = temp;
        return;
    }

    queue->tail->ptrNext = temp;
    queue->tail = temp;
    return;
}

void deQueue(Queue* const queue){
    if(queue->head == nullptr){
        std::cout << "fila vazia" << std::endl;
        return;
    }

    Node* temp = queue -> head;

    queue -> head = temp -> ptrNext;

    std::cout << "o elemento removido é: " << temp -> iData << std::endl;

    if (queue->head == nullptr){
        queue->tail = nullptr;
    }

    free(temp);
    return;
}

void showFirstElement(Queue* const queue){
    std::cout << "o primeiro elemento é: " << ((queue->head != nullptr) ? queue->head->iData : -1) << std::endl;
}

void showLastElement(Queue* const queue){
    std::cout << "o ultimo elemento é: " << ((queue->tail!= nullptr) ? queue->tail->iData : -1) << std::endl;
}

void showElements(Queue* const queue){
    if(queue->head == nullptr){
        std::cout << "fila vazia" << std::endl;
        return;
    }

    Node* current = queue->head;

    int iCounter = 1;
    while (current != nullptr){
        std::cout << "o elemento " << iCounter << " da fila é: " << current -> iData << std::endl;
        current = current -> ptrNext;
        iCounter++;
    }
    return;
}