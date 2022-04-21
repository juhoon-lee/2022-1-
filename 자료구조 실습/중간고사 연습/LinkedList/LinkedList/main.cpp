#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class singlyLinkedList {
public:
    singlyLinkedList();
    bool empty();
    void append(int data);
    void insertion(int idx, int data);
    void deletion(int idx);
    void print();
    
private:
    node* head;
    node* tail;
    int listSize;
};

singlyLinkedList::singlyLinkedList() {
    head = NULL;
    tail = NULL;
    listSize = 0;
}

bool singlyLinkedList::empty() {
    if (listSize == 0) {
        return true;
    }
    else {
        return false;
    }
}

void singlyLinkedList::append(int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    
    if (empty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    listSize++;
}

void singlyLinkedList::insertion(int idx, int data) {
    if (idx < 0 || idx > listSize) {
        return;
    }
    else if (idx == listSize) {
        append(data);
    }
    else if (idx == 0) {
        node* newNode = new node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        listSize++;
    }
    else {
        node* newNode = new node;
        newNode->data = data;
        node* curNode = head;
        for (int i = 0; i < idx-1; i++) {
            curNode = curNode->next;
        }
        newNode->next = curNode->next;
        curNode->next = newNode;
        listSize++;
    }
}

void singlyLinkedList::deletion(int idx) {
    if (empty() || idx < 0 || idx >= listSize) {
        return;
    }
    
    node* curNode = head;
    if (idx == 0) {
        if (listSize == 1) {
            head = tail = NULL;
        }
        else {
            head = head->next;
        }
    }
    else {
        node* preNode = head;
        for (int i = 0; i < idx; i++) {
            preNode = curNode;
            curNode = curNode->next;
        }
        preNode->next = curNode->next;
        if (curNode == tail) {
            tail = preNode;
        }
    }
    delete curNode;
    listSize--;
}

void singlyLinkedList::print() {
    if (empty()) {
        cout << "empty";
    }
    node* curNode = head;
    while (curNode != NULL) {
        cout << curNode->data << " ";
        curNode = curNode->next;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
