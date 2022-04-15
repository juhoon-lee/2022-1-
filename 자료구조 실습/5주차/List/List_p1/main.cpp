#include <iostream>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

class nodeList {
public:
    nodeList();
    bool empty();
    int size();
    node* begin();
    node* end();
    void insert(node* pos, int data);
    void insertFront(int data);
    void insertBack(int data);
    void erase(node* pos);
    void eraseFront();
    void eraseBack();
    
private:
    node* header;
    node* trailer;
    int n;
};


nodeList::nodeList() {
    header = new node();
    trailer = new node();
    header -> next = trailer;
    trailer -> prev = header;
    header -> prev = NULL;
    trailer -> next = NULL;
    n = 0;
}

bool nodeList::empty() {
    return (n == 0);
}

int nodeList::size() {
    return n;
}

node* nodeList::begin() {
    return header -> next;
}

node* nodeList::end() {
    return trailer;
}

void nodeList::insert(node *pos, int data) {
    node* newNode = new node();
    node* prevNode = pos->prev;
    newNode->data = data;
    newNode->prev = pos->prev;
    newNode->next = pos;
    prevNode->next = newNode;
    pos->prev = newNode;
    n++;
}

void nodeList::insertFront(int data) {
    insert(begin(), data);
}

void nodeList::insertBack(int data) {
    insert(end(), data);
}

void nodeList::erase(node *pos) {
    node* prevNode = pos->prev;
    node* nextNode = pos->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete pos;
    n--;
}

void nodeList::eraseFront() {
    erase(begin());
}

void nodeList::eraseBack() {
    erase(end()->prev);
}


int main(int argc, const char * argv[]) {
    
    nodeList example = nodeList();
    
    return 0;
}
