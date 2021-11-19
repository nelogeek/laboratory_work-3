#include <iostream>
using namespace std;

struct Node {
    char* data;
    Node* next;

    Node(char* _data) : data(_data), next(nullptr) {}

};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(char* _data) {
        Node* node = new Node(_data);
        if (is_empty()) {
            first = node;
            last = node;
            return;
        }
        last->next = node;
        last = node;
    }

    void push_forward(char* _data) {
        if (is_empty()) {
            Node* node = new Node(_data);
            first = node;
            last = node;
            return;
        }
        Node* node = new Node(_data);
        Node* temp = first;
        first = node;
        first->next = temp;
    }

    void insert(char* _data, size_t index) {
        if (is_empty()) return;
        Node* node = first;
        for (int i = 0; i < index; i++) {
            node = node->next;
            if (!node) return;
        }
        Node* temp = node;
        Node* new_node = new Node(_data);
        node = new_node;
        node->next = temp;
    }

    Node* operator[] (size_t index) {
        if (is_empty()) return nullptr;
        Node* node = first;
        for (int i = 0; i < index; i++) {
            node = node->next;
            if (!node) return nullptr;
        }
        return node;
    }

    list operator+ (list second) {
        last->next = second.first;
        last = second.last;
        list l;
        l.first = first;
        l.last = last;
        return l;
    }

    Node* get_by_data(char* _data) {
        if (is_empty()) return nullptr;
        Node* node = first;
        while (node) {
            if (node->data == _data) return node;
            node = node->next;
        }
        return nullptr;
    }


    char* get_data(size_t index) {
        if (is_empty()) return nullptr;
        Node* node = first;
        for (int i = 0; i < index; i++) {
            node = node->next;
            if (!node) return nullptr;
        }
        return node->data;
    }

    void remove_first() {
        if (is_empty()) return;
        Node* node = first;
        first = node->next;
        delete node;
    }

    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* node = first;
        while (node->next != last) node = node->next;
        node->next = nullptr;
        delete last;
        last = node;
    }

    void remove(string _data) {
        if (is_empty()) return;
        if (first->data == _data) {
            remove_first();
            return;
        }
        else if (last->data == _data) {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->data != _data) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    void remove_all(Node* node) {
        if (node->next) {
            remove_all(node->next);
            delete node;
        }
        else {
            delete node;
        }
    }

    void remove_all() {
        if (is_empty()) return;
        remove_all(first->next);
        first = nullptr;
    }


    void print() {
        if (is_empty()) return;
        Node* node = first;
        while (node) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }



};
