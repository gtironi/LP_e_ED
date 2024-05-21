#include <iostream>

using namespace std;

typedef struct Node {
    int iId;
    Node* ptrNext;
    Node* ptrPrev;

} Node;

Node* createNode(int iValue){
    Node* temp = (Node*) malloc(sizeof(Node));

    temp->iId = iValue;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;

    return temp;
}

void addEnd(Node** head, int iValue) {

    //não vou tratar excessão pq já fiz durante o teste

    Node* temp = createNode(iValue);

    if ((*head) == nullptr) {
        (*head) = temp;
        (*head)->ptrNext = (*head);
        (*head)->ptrPrev = (*head);
    } else {
        Node* ptrTail = (*head)->ptrPrev;
        ptrTail->ptrNext = temp;
        temp->ptrPrev = ptrTail;
        temp->ptrNext = (*head);
        (*head)->ptrPrev = temp;
    }
}

void displayElements(Node* head) {
    if (head == nullptr) {
        cout << "displayElements: A lista está vazia." << endl;
        return;
    }

    Node* ptrCurrent = head;

    cout << "Lista: [" << ptrCurrent -> iId;

    ptrCurrent = ptrCurrent -> ptrNext;

    while (ptrCurrent != head) {
        cout <<  ", " << ptrCurrent->iId;
        ptrCurrent = ptrCurrent->ptrNext;
    }

    cout << "]" << endl;
}

Node* mergePlaylists(Node* head1, Node* head2) {
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }

    Node* newHead = nullptr;
    Node* ptrCurrent1 = head1;
    Node* ptrCurrent2 = head2;

    //Adiciono os dois primeiros elementos
    addEnd(&newHead, ptrCurrent1->iId);
    addEnd(&newHead, ptrCurrent2->iId);
    ptrCurrent1 = ptrCurrent1->ptrNext;
    ptrCurrent2 = ptrCurrent2->ptrNext;

    while (ptrCurrent1 != head1 || ptrCurrent2 != head2) {
        if (ptrCurrent1 != head1) {
            addEnd(&newHead, ptrCurrent1->iId);
            ptrCurrent1 = ptrCurrent1->ptrNext;
        }
        if (ptrCurrent2 != head2) {
            addEnd(&newHead, ptrCurrent2->iId);
            ptrCurrent2 = ptrCurrent2->ptrNext;
        }
    }

    return newHead;
}

bool hasLoop(Node* head) {
    if (head == nullptr || head->ptrNext == nullptr) {
        return false;  // Lista vazia ou com apenas um nó
    }

    Node* ptrSlow = head;
    Node* ptrFast = head->ptrNext;

    // Verifica loops que avançam
    while (ptrFast != nullptr && ptrFast->ptrNext != nullptr) {
        if (ptrSlow == ptrFast) {
            return true;  // Encontrou um loop 
        }
        ptrSlow = ptrSlow->ptrNext;
        ptrFast = ptrFast->ptrNext->ptrNext;
    }

    Node* ptrLast = head;

    // Encontra o último nó (não é circular)
    while (ptrLast->ptrNext != nullptr) {
        ptrLast = ptrLast->ptrNext;
    }

    ptrSlow = ptrLast;
    ptrFast = ptrLast->ptrPrev;

    // Verifica loops que retornam
    while (ptrFast != nullptr && ptrFast->ptrPrev != nullptr) {
        if (ptrSlow == ptrFast) {
            return true;  // Encontrou um loop
        }
        ptrSlow = ptrSlow->ptrPrev;
        ptrFast = ptrFast->ptrPrev->ptrPrev;
    }

    return false;  // Não encontrou um loop
}

int main() {

    cout << "---------------- 1c ----------------" << endl;

    Node* playlist1 = nullptr;
    Node* playlist2 = nullptr;

    // Adicionando elementos à primeira playlist
    addEnd(&playlist1, 1);
    addEnd(&playlist1, 3);
    addEnd(&playlist1, 5);

    // Adicionando elementos à segunda playlist
    addEnd(&playlist2, 2);
    addEnd(&playlist2, 4);
    addEnd(&playlist2, 6);
    addEnd(&playlist2, 8);
    addEnd(&playlist2, 9);
    addEnd(&playlist2, 10);

    cout << "Playlist 1: ";
    displayElements(playlist1);

    cout << "Playlist 2: ";
    displayElements(playlist2);

    // Mesclando as playlists
    Node* mergedPlaylist = mergePlaylists(playlist1, playlist2);

    cout << "Playlist mesclada: ";
    displayElements(mergedPlaylist);

    cout << "---------------- 2 ----------------" << endl;

    cout << "Testando para uma lista circular duplamente encadeada" << endl;

    Node* myList = nullptr;

    // Criando uma lista encadeada com um loop
    addEnd(&myList, 1);
    addEnd(&myList, 2);
    addEnd(&myList, 3);
    addEnd(&myList, 4);
    addEnd(&myList, 5);

    // Verificando se há um loop na lista
    bool loopExists = hasLoop(myList);

    if (loopExists) {
        cout << "A lista possui um loop." << endl;
    } else {
        cout << "A lista não possui um loop." << endl;
    }

    cout << "\nTestando para uma lista duplamente encadeada" << endl;

    myList = nullptr;

    // Criando uma lista encadeada com um loop
    addEnd(&myList, 1);
    addEnd(&myList, 2);
    addEnd(&myList, 3);
    addEnd(&myList, 4);
    addEnd(&myList, 5);

    // Tirando o loop da lista
    Node* ptrLast = myList -> ptrPrev;

    myList -> ptrPrev = nullptr;
    ptrLast -> ptrNext = nullptr;

    // Verificando se há um loop na lista
    loopExists = hasLoop(myList);

    if (loopExists) {
        cout << "A lista possui um loop." << endl;
    } else {
        cout << "A lista não possui um loop." << endl;
    }

    cout << "\nTestando para uma lista com loop voltando" << endl;

    myList -> ptrNext -> ptrPrev = myList -> ptrNext -> ptrNext;

    // Verificando se há um loop na lista
    loopExists = hasLoop(myList);

    if (loopExists) {
        cout << "A lista possui um loop." << endl;
    } else {
        cout << "A lista não possui um loop." << endl;
    }

    cout << "\nTestando para uma lista com loop indo" << endl;

    myList = nullptr;

    // Criando uma lista encadeada com um loop
    addEnd(&myList, 1);
    addEnd(&myList, 2);
    addEnd(&myList, 3);
    addEnd(&myList, 4);
    addEnd(&myList, 5);

    // Tirando o loop da lista
    ptrLast = myList -> ptrPrev;

    myList -> ptrPrev = nullptr;
    ptrLast -> ptrNext = nullptr;

    myList -> ptrNext -> ptrNext = myList -> ptrNext;
    // Verificando se há um loop na lista
    loopExists = hasLoop(myList);

    if (loopExists) {
        cout << "A lista possui um loop." << endl;
    } else {
        cout << "A lista não possui um loop." << endl;
    }

    return 0;
}