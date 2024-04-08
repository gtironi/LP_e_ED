#include <iostream>

typedef struct Node{
    int iData;
    Node* ptrNext;
} Node;

typedef struct Stack{
    Node* top;
} Stack;

Node* newNode(int);
Stack* newStack();
void push(Stack* const, int);
void pop(Stack* const);
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
    Node* temp = (Node*) malloc(sizeof(Node));

    temp -> iData = iValue;
    temp -> ptrNext = nullptr;

    return temp;
}

Stack* newStack(){
    Stack* temp = (Stack*) malloc(sizeof(Stack));

    temp -> top = nullptr;

    return temp;
}

void push(Stack* const stack, int iValue){
    
    Node* temp = newNode(iValue);

    if(stack -> top == nullptr){
        stack -> top = temp;
        return;
    }

    temp -> ptrNext = stack -> top;
    stack -> top =  temp;

    return;
}

void pop(Stack* const stack){
    if(stack -> top == nullptr){
        std::cout << "pilha vazia" << std::endl;
        return;
    }

    Node* temp = stack -> top;

    std::cout << "elemento removido: " << temp -> iData << std::endl;

    stack -> top = temp -> ptrNext;

    free(temp);

    return;
}

void showTopElement(Stack* const stack){
    std::cout << "primeiro elemento (pilha vazia = -1): " << ((stack -> top != nullptr) ? stack -> top -> iData : -1) << std::endl;
    return;
}

void showElements(Stack* const stack){
    Node* current = stack -> top;

    if(current == nullptr){
        std::cout << "pilha vazia" << std::endl;
        return;
    }

    int iCounter = 1;

    while(current != nullptr){
        std::cout << "elemento " << iCounter << " da pilha: " << current -> iData << std::endl;
        current = current -> ptrNext;
        iCounter++;
    }

    return;
}