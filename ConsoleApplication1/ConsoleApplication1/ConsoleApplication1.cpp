#include "Header.h"


int main() {
    list l;
    list l2;
    l.push_back((char*)"1");
    l.push_back((char*)"2");
    l2.push_back((char*)"3");
    l2.push_back((char*)"4");
    list l3 = l + l2;

    l3.print();
    return 0;
}