#include <iostream>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

class DoubleLinkedList {
public:
    DoubleLinkedList();
    void print();
    void append(int data);
    int deleteNode(int idx);
    void printReverse();
    void Update(int x, int y);
    bool isEmpty();
private:
    node* header;
    node* trailer;
    int listSize;
};

DoubleLinkedList::DoubleLinkedList() {
    header = new node();
    trailer = new node();
    header->prev = NULL;
    header->next = trailer;
    trailer->next = NULL;
    trailer->prev = header;
    listSize = 0;
}

void DoubleLinkedList::print() {
    node* curNode = header;
    if (isEmpty()) {
        cout << "empty" << endl;
        return;
    }
    while (curNode->next != trailer) {
        cout << curNode->next->data << " ";
        curNode = curNode->next;
    }
    cout << endl;
}

void DoubleLinkedList::append(int data) {
    node* newNode = new node();
    newNode->data = data;
    newNode->prev = trailer->prev;
    trailer->prev->next = newNode;
    trailer->prev = newNode;
    newNode->next = trailer;
    
    listSize++;
    print();
}

int DoubleLinkedList::deleteNode(int idx) {
    if (isEmpty() || idx >= listSize) {
        return -1;
    }
    node* delNode = header;
    for (int i = 0; i < idx+1; i++) {
        delNode = delNode->next;
    }
    
    delNode->prev->next = delNode->next;
    delNode->next->prev = delNode->prev;
    
    int result = delNode->data;
    delete delNode;
    listSize--;
    return result;
}

void DoubleLinkedList::printReverse() {
    node* curNode = trailer;
    if (isEmpty()) {
        cout << "empty" << endl;
        return;
    }
    while (curNode->prev != header) {
        cout << curNode->prev->data << " ";
        curNode = curNode->prev;
    }
    cout << endl;
}

void DoubleLinkedList::Update(int x, int y) {
    if (isEmpty()) {
        cout << "empty" << endl;
        return;
    }
    node* curNode = header;
    bool check = false;
    while (curNode->next != trailer) {
        curNode = curNode->next;
        if (curNode->data == x) {
            curNode->data = y;
            check = true;
        }
    }
    if (!check) {
        cout << "Not found" << endl;
        return;
    }
    print();
}

bool DoubleLinkedList::isEmpty() {
    return listSize == 0 ? true : false;
}

int main(int argc, const char * argv[]) {
    
    DoubleLinkedList A = DoubleLinkedList();
    
    int orderCount, x, y;
    string order;
    cin >> orderCount;
    
    for (int i = 0; i < orderCount; i++) {
        cin >> order;
        if (order == "Print") {
            A.print();
        }
        else if (order == "Append") {
            cin >> x;
            A.append(x);
        }
        else if (order == "Delete") {
            cin >> x;
            cout << A.deleteNode(x) << endl;
        }
        else if (order == "Print_reverse") {
            A.printReverse();
        }
        else if (order == "Update") {
            cin >> x >> y;
            A.Update(x, y);
        }
    }
    
    return 0;
}
