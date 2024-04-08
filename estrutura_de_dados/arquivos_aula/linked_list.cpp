#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef struct Node
{
    int iData;
    Node* ptrNext;
} Node;
 
typedef struct LinkedList
{
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
    cout << "====================" << endl;

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