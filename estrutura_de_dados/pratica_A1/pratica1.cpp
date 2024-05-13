#include <iostream>

typedef struct Node
{
    int iData;
	Node* ptrNext;
} Node;

typedef struct Queue
{
    Node* head;
    Node* tail;
} Queue;

Queue* newQueue();
Node* newNode(int iValue);
void enQueue(Queue* const queue, int iValue);
void deQueue(Queue* const queue);
void showFirstElement(Queue* const queue);
void showLastElement(Queue* const queue);
void showElements(Queue* const queue);

int main()
{
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

Queue* newQueue()
{
    Queue* temp = new Queue;

    temp->head = nullptr;
    temp->tail = nullptr;

    return temp;
}

Node* newNode(int iValue)
{
    Node* temp = new Node;

    temp->iData = iValue;
    temp->ptrNext = nullptr;

    return temp;
}

void enQueue(Queue* const queue, int iValue)
{
    Node* temp = newNode(iValue);

    if (queue->head == nullptr){
        queue->head = temp;
        queue->tail = temp;
        return;
    }
    else{
        queue->tail->ptrNext = temp;
        queue->tail = temp;    
    }
}

void deQueue(Queue* const queue)
{
    if (queue->head == nullptr){
        std::cout << "fila vazia" << std::endl;
        return;
    }

    Node* temp = queue->head;

    std::cout << "elemento " <<  temp->iData <<  " removido" << std::endl;

    queue->head = queue->head->ptrNext;

    if (queue->head == nullptr){
        queue->tail = nullptr;
    }

    delete temp;
};

void showFirstElement(Queue* const queue)
{
    Node* temp = queue->head;

    std::cout << "o primeiro elemento da fila é:" << ((temp != nullptr) ? temp->iData : -1) << std::endl;
}

void showLastElement(Queue* const queue)
{
    Node* temp = queue->tail;

    std::cout << "o primeiro elemento da fila é:" << ((temp != nullptr) ? temp->iData : -1) << std::endl;
}

void showElements(Queue* const queue)
{
    if (queue->head == nullptr){
        std::cout << "fila vazia" << std::endl;
        return;
    }

    Node* current = queue->head;

    int iCounter = 1;
    while (current != nullptr){
        std::cout << "o elemento " << iCounter << " da fila é:" << current->iData << std::endl;
        current = current->ptrNext;
        iCounter++;
    }

}