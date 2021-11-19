#include "Header_.h"


int main() {
    
    Node* head1 = NULL;
    Node* temp = new Node;

    for (int i = 9; i > 0; i--) {
        head1 = addHead(head1, i);
    }
    outList(head1);
   
    Node* head2 = reverse(head1);
    outList(head2);      // вывод в процессе обхода списка
    
    
    return 0;
}