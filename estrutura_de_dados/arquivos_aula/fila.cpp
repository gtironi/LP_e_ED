#include <iostream>

using namespace std;

// Filas 
// Estruturas FIFO, ou FCFS (First Come, First Served).

// Pilhas
// Esturas LIFO, LCFS (Last Come, First Served).

typedef struct Node{
    int iData;
    Node* next;
} Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
} Queue;

Queue* newQueue(){
    // Precisamos pedir memoria para o SO.
    // (pinho) Queue* temp = (Queue*) malloc(sizeof(Queue));
    Queue* temp = new Queue;

    // Fila vazia: primeiro e último elementos nulos.
    temp->front = nullptr;
    temp->rear = nullptr;

    return temp;
}

Node* newNode(int iValue){
    // (pinho) Node* temp = (Node*) malloc(sizeof(Node));
    Node* temp = new Node;

    temp->iData = iValue;
    temp->next = nullptr;

    return temp;
}

void enQueue(Queue* const queue, int iValue){
    // Adiciona elemento na fila.

    // Cria novo nó
    Node* temp = newNode(iValue);

    // Se a fila estiver vazia...
    if (queue -> rear == nullptr){
        // ...primeiro e último elemento são iguais.
        queue->front = temp;
        queue->rear = temp;
    }
    // Senão, adiciona elemento no final.
    else{
        queue->rear->next = temp;
        queue->rear = temp;
    }
}

void deQueue(Queue* const queue){
    // Remove elemento da fila.

    // Se a fila estiver vazia.
    if (queue -> front == nullptr){
        cout << "fila vazia" << endl;
        return;
    }

    // No inicio reservamos o endereço do elemento que vamos apagar para
    // que no final uma única variável saiba o endereço dele e possamos
    // deletá-lo da memória.
    Node* temp = queue->front;

    cout << "Elemento " << temp->iData << " removido." << endl;

    // Transforma o next do primeiro elemento no novo primeiro elemento.
    queue->front = queue->front->next;

    if (queue->front == nullptr){
        // fila vazia
        queue->rear = nullptr;
    }

    // libera memória alocada o que era o primeiro elemento.
    // (pinho) free(temp);
    delete temp;
}

void showFirstElement(Queue* const queue){
    cout << "Primeiro elmento da fila: " << ((queue->front != NULL) ? queue->front->iData : -1) << endl;
}

void showLastElement(Queue* const queue){
    cout << "Último elmento da fila: " << ((queue->rear != NULL) ? queue->rear->iData : -1) << endl;
}

void showElements(Queue* const queue){
    // Percorre toda a fila exibindo seu elementos.

    //Fila vazia.
    if (queue->front == nullptr){
        cout << "fila vazia" << endl;
        return;
    }

    Node* current = queue->front;

    int iCounter = 1;
    while(current != nullptr){
        cout << "Elemento " << iCounter << " da fila: " << current->iData << endl;
        current = current->next;
        iCounter++;
    }
}

int main(){
    //1. Estrutura de um nó
    //2. Estrutura de uma fila
    //3. Função que cria uma fila
    //4. Função que cria um nó
    //5. Função que enfileira um nó
    //6. Função que exibe primeiro elemento
    //7. Função que exibe último elemento
    //8. Função que remove um nó

    Queue* queue = newQueue();
    showFirstElement(queue);
    showLastElement(queue);

    cout << "==========================================" << endl;

    // adicionando elementos na fila
    enQueue(queue, 0);
    showFirstElement(queue);
    showLastElement(queue);
    
    cout << "==========================================" << endl;

    enQueue(queue, 10);
    showFirstElement(queue);
    showLastElement(queue);

    cout << "==========================================" << endl;

    enQueue(queue, 11);
    enQueue(queue, 12);
    enQueue(queue, 13);
    enQueue(queue, 14);
    enQueue(queue, 15);
    showElements(queue);

    cout << "==========================================" << endl;

    Queue* queue2 = newQueue();

    deQueue(queue);

    showElements(queue);

    deQueue(queue2);

    cout << "==========================================" << endl;

    return 0;
}