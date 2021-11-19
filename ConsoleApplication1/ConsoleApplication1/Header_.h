#include <iostream>
#include <iomanip>

using namespace std;

struct  Node {

    int data;   //информационное поле

    Node* next; //адресное поле

};

//-------------------------------------------------------------

Node* addHead(Node* head, int val) {

    Node* temp = new Node;  //новый узел Ц включаемый элемент

    temp->next = head;

    temp->data = val;

    head = temp;

    return head;

}

//-----------вывод--------------------------------------------------

void outList(Node* head) {

    Node* temp = head;

    while (temp != NULL) {

        cout << setw(5) << temp->data << ' ';

        temp = temp->next;

    }

    cout << endl;

}

//-------количество узлов-------------------------------------------

int countNode(Node* head) {

    Node* temp = head;

    int count = 0;

    while (temp != NULL) {

        count++;

        temp = temp->next;

    }

    return count;

}

//----------------по значению---------------------------------------

Node* findData(Node* head, int val) {

    Node* temp = head;

    while (temp != NULL) {

        if (temp->data == val) return temp;

        temp = temp->next;

    }

    return NULL;

}

//----------------по позиции---------------------------------------

Node* findPos(Node* head, int pos) {

    Node* temp = head;

    while (temp != NULL && pos > 1) {

        temp = temp->next;

        pos--;

    }

    return temp;

}

//-------------------------------------------------------------

void insertAfter(Node* p, Node* temp) {

    if (p == NULL) return;

    temp->next = p->next;

    p->next = temp;

}

//-------------------------------------------------------------

bool insertPos(Node* head, int pos, int val) {

    if (pos == 1)  return false; // функци€ addHead

    Node* p = findPos(head, pos - 1); //поиск предыдущего узла

    if (p == NULL)  return false;

    Node* temp = new Node;

    temp->data = val;

    temp->next = p->next;

    p->next = temp;

    return true;

}

//-------------------------------------------------------------

Node* removeHead(Node* head) {

    if (head == NULL) return 0;

    Node* temp = head;   //указатель удал€емого узла

 //начало списка - это  указатель на следующий узел из удал€емого  

    head = temp->next;

    delete temp;        //удал€ем узел

    return head;           //возвращаем новое начало списка

}

//-------------------------------------------------------------

void remove(Node*& head, Node* p) {

    if (head == p)

        head = removeHead(head);

    Node* temp = head;

    while (temp->next && temp->next != p)

        temp = temp->next;

    if (temp->next) {

        temp->next = temp->next->next;

        delete p;

    }

}

//-------------------------------------------------------------

bool  isEmpty(Node* head) {

    return head == NULL;

}

//-------------------------------------------------------------

Node* reverse(Node* head) {
    Node* new_node = 0;
    while (head) {
        Node* next = head->next;
        head->next = new_node;
        new_node = head;
        head = next;
    }
    return new_node;
}