#include <iostream>

using std::cout;
using std::endl;

//struct
typedef struct Node {
    int iData;
    Node* ptrNext;
} Node;

typedef struct LinkedList {
    Node* ptrFirst;
} LinkedList;

//functions names
Node* newNode(int);
LinkedList* newLinkedList();
void showFirstElement(LinkedList* const);
void showLastElement(LinkedList* const);
void showElements(LinkedList* const);
void addElement(LinkedList* const, int);
void removeElement(LinkedList* const, int);

// main
int main(){
    
    LinkedList* linkedList = newLinkedList();
    // LinkedList* linkedList = nullptr;

    showFirstElement(linkedList);
    showElements(linkedList);
    showLastElement(linkedList);
    
    cout << "====================" << endl;
    
    addElement(linkedList, 0);
    addElement(linkedList, 3);
    addElement(linkedList, 7);
    addElement(linkedList, 13);
    addElement(linkedList, 42);
    
    showFirstElement(linkedList);
    showLastElement(linkedList);
    showElements(linkedList);
    cout << "====================" << endl;
    
    removeElement(linkedList, 666);
    showElements(linkedList);
    removeElement(linkedList, 7);
    showElements(linkedList);

    return 0;
}

//functions definition

Node* newNode(int iValue){
    Node* temp = (Node*) malloc(sizeof(Node));

    temp -> iData = iValue;
    temp -> ptrNext = nullptr;

    return temp;
}

LinkedList* newLinkedList(){
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));

    temp -> ptrFirst = nullptr;

    return temp;
}

void showFirstElement(LinkedList* const linkedList){
    if(linkedList == nullptr || linkedList -> ptrFirst == nullptr){
        cout << "Lista vazia!" << endl;
        return;
    }

    cout << "Primeiro elemento da Lista: " << linkedList -> ptrFirst -> iData << endl;

    return;
}

void showLastElement(LinkedList* const linkedList){
    if(linkedList == nullptr || linkedList -> ptrFirst == nullptr){
        cout << "Lista vazia!" << endl;
        return;
    }

    Node* lastElement = linkedList -> ptrFirst;

    while(lastElement -> ptrNext != nullptr){
        lastElement = lastElement -> ptrNext;
    }

    cout << "Último elemento da Lista: " << lastElement -> iData << endl;

    return;
}

void addElement(LinkedList* const linkedList, int iValue){
    Node* temp = newNode(iValue);

    if(linkedList == nullptr){
        cout << "A lista não existe!" << endl;
        return;
    }
    if( linkedList -> ptrFirst == nullptr){
        linkedList -> ptrFirst = temp;
        return;
    }

    Node* lastElement = linkedList -> ptrFirst;

    while(lastElement -> ptrNext != nullptr){
        lastElement = lastElement -> ptrNext;
    }

    lastElement -> ptrNext = temp;
    return;
}

void removeElement(LinkedList* const linkedList, int iValue){
    if(linkedList == nullptr){
        cout << "A lista não existe!" << endl;
        return;
    }
    if( linkedList -> ptrFirst == nullptr){
        cout << "Lista vazia!" << endl;
        return;
    }

    Node* current = linkedList -> ptrFirst;
    Node* previous = nullptr;

    if(current -> iData == iValue){
        linkedList -> ptrFirst = current -> ptrNext;
        free(current);
        return;
    }

    while (current != nullptr && current -> iData != iValue){
        previous = current;
        current = current -> ptrNext;
    }

    if(current == nullptr){
        cout << "Elemento não encontrado na lista!" << endl;
        return;
    }

    previous -> ptrNext = current -> ptrNext;
    
    free(current);

    return;
}

void showElements(LinkedList* const linkedList){
    if(linkedList == nullptr || linkedList -> ptrFirst == nullptr){
        cout << "Lista vazia!" << endl;
        return;
    }

    Node* current = linkedList -> ptrFirst;

    cout << "Elementos da lista: [";

    while (current -> ptrNext != nullptr){
        cout << current -> iData << " ";
        current = current -> ptrNext;
    }

    cout << current -> iData << "]" << endl;

    return;
}