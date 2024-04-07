#include <iostream>

typedef struct Node {
    int iData;
    Node* prtNext;
} Node;

typedef struct Stack {
    Node* head;
} Stack;

Stack* newStack();
Node* newNode(int);
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

    temp->iData = iValue;
    temp->prtNext = nullptr;

    return temp;
}

Stack* newStack(){
    Stack* temp = (Stack*) malloc(sizeof(Stack));

    temp->head = nullptr;

    return temp;
}

void push(Stack* const stack, int iValue){
    Node* temp = newNode(iValue);

    temp->prtNext = stack->head; 
    stack->head = temp;
    
    return;
}

void pop(Stack* const stack){

    if (stack->head == nullptr){
        std::cout << "Pilha vazia" << std::endl;
        return;
    }

    Node* temp = stack->head;

    std::cout << "elemento retirado: " << temp->iData << std::endl;

    stack->head = temp->prtNext;

    free(temp);

    return;
}

void showTopElement(Stack* const stack){
    if (stack->head == nullptr){
        std::cout << "Pilha vazia" << std::endl;
        return;
    }
    else{
        std::cout << "O primeiro elemento é: " << stack->head->iData << std::endl;
        return;
    }
    //((stack->head != nullptr) ? stack->head->iData: -1))
}

void showElements(Stack* const stack){
    if (stack->head == nullptr){
        std::cout << "Pilha vazia" << std::endl;
        return;
    }

    Node* current = stack->head;

    int iCounter = 1;
    while (current != nullptr){
        std::cout << "O elemento " << iCounter << " da pilha é: " << current->iData << std::endl;
        current = current->prtNext;
        iCounter++;
    }

    return;
}