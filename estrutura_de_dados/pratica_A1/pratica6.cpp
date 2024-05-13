#include <iostream>


typedef struct Node{
    int iData;
    Node* ptrNext;
} Node;

typedef struct Stack{
    Node* ptrTop;
} Stack;

Node* newNode(int);
Stack* newStack();
void pop(Stack* const);
void push(Stack* const, int);
void showTopElement(Stack* const);
void showElements(Stack* const);

int main(){
Stack* stack = newStack();
	
	pop(stack);
	showTopElement(stack);
	std::cout << "-----" <<std::endl;
	push(stack, 1);
	showTopElement(stack);
	std::cout << "-----" <<std::endl;
	push(stack, 5);
	showTopElement(stack);
	std::cout << "-----" <<std::endl;
	push(stack, 42);
	showTopElement(stack);
	std::cout << "-----" <<std::endl;
	push(stack, 666);
	showTopElement(stack);
	std::cout << "===============" <<std::endl;
	showElements(stack);

	std::cout << "==========================================" <<std::endl;

	pop(stack);
	std::cout << "-----" <<std::endl;
	showElements(stack);

    return 0;
}

Node* newNode(int iValue){
    Node* ptrTemp = (Node*) malloc(sizeof(Node));

    ptrTemp -> iData = iValue;
    ptrTemp -> ptrNext = nullptr;

    return ptrTemp;
}

Stack* newStack(){
    Stack* ptrTemp = (Stack*) malloc(sizeof(Stack));

    ptrTemp -> ptrTop= nullptr;

    return ptrTemp;
}

void push(Stack* const ptrStack, int iValue){

    Node* ptrTemp = newNode(iValue);

    ptrTemp -> ptrNext = ptrStack -> ptrTop;
    ptrStack -> ptrTop = ptrTemp;

    return;
}

void pop(Stack* const ptrStack){
    Node* ptrDeletar = ptrStack -> ptrTop;

    if(ptrDeletar == nullptr){
        std::cout << "Pilha vazia" << std::endl;
        return;
    }

    ptrStack -> ptrTop = ptrDeletar -> ptrNext;

    free(ptrDeletar);

    return;
}

void showTopElement(Stack* const ptrStack){
    std::cout << "O elemento do topo da pilha é: " << ((ptrStack -> ptrTop != nullptr) ? ptrStack -> ptrTop -> iData : -1) << std::endl;
    return;
}

void showElements(Stack* const ptrStack){
    Node* ptrCurrent = ptrStack -> ptrTop;

    if(ptrCurrent == nullptr){
        std::cout << "Pilha vazia" << std::endl;
        return;
    }

    int iCounter = 1;
    while (ptrCurrent != nullptr){
        std::cout << "O elemento " << iCounter << " da pilha é: " << ptrCurrent -> iData << std::endl;
        ptrCurrent = ptrCurrent ->  ptrNext;
        iCounter++;
    }

    return;
}