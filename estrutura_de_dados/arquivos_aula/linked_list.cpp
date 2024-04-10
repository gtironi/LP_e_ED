#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef struct Node{
    int iData;
    Node* ptrNext;
} Node;
 
typedef struct LinkedList{
    Node* ptrFirst;
} LinkedList;
 
LinkedList* newLinkedList();
Node* newNode(int);
void showFirstElement(LinkedList* const);
void showLastElement(LinkedList* const);
void showElements(LinkedList* const);
void addElement(LinkedList* const, int);
void removeElement(LinkedList* const, int);

int main()
{
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

LinkedList* newLinkedList()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
    temp->ptrFirst = nullptr; 

    return temp;
}

Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iData = iValue;
    temp->ptrNext = nullptr;
    
    return temp;
}

void showFirstElement(LinkedList* const linkedList)
{
    if(linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "showFirstElement: Lista Vazia" << endl;
    }
    else
    {
        cout << "Primeiro da Lista: " << linkedList->ptrFirst->iData << endl;
    }
}

void showLastElement(LinkedList* const linkedList)
{
    if(linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "showLastElement: Lista Vazia" << endl;
    }
    else
    {
        Node* lastNode = linkedList->ptrFirst;
        
        while (lastNode->ptrNext != nullptr)
        {
            lastNode = lastNode->ptrNext;
        }
        
        cout << "Último da Lista: " << lastNode->iData << endl;
    }
}

void showElements(LinkedList* const linkedList)
{
    if(linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "showElements: Lista Vazia" << endl;
    }
    else
    {
        Node* current = linkedList->ptrFirst;
        
        cout << "Elementos da Lista:";
        
        while (current != nullptr)
        {
            cout << " " << current->iData;
            current = current->ptrNext;
        }
        cout << endl;
    }
}

void addElement(LinkedList* const linkedList, int iValue)
{
    Node* temp = newNode(iValue);
    
    if(linkedList == nullptr)
    {
        cout << "addElement: Lista é nula" << endl;
        return;
    }
    
    if(linkedList->ptrFirst == nullptr)
    {
        linkedList->ptrFirst = temp;
    }
    else
    {
        Node* current = linkedList->ptrFirst;
        
        while (current->ptrNext != nullptr)
        {
            current = current->ptrNext;
        }
        
        current->ptrNext = temp;
    }
}

void removeElement(LinkedList* const linkedList, int iValue)
{
    if(linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "removeElement: Lista Vazia" << endl;
        return;
    }
    
    Node* current = linkedList->ptrFirst;
    Node* previous = nullptr;
    
    // Case 1: Removing the first node
    if (current->iData == iValue)
    {
        linkedList->ptrFirst = current->ptrNext;
        free(current);
        return;
    }
    
    // Case 2: Removing a node in the middle
    while (current != nullptr && current->iData != iValue)
    {
        previous = current;
        current = current->ptrNext;
    }
    
    if (current == nullptr)
    {
        cout << "Elemento não encontrado na lista" << endl;
        return;
    }
    
    previous->ptrNext = current->ptrNext;
    free(current);
    return;
}
