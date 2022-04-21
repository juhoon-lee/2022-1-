#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class listStack {
public:
    listStack();
    bool empty();
    int size();
    int top();
    void push(int data);
    void pop();
    
private:
    node* topNode;
    int listSize;
};

listStack::listStack() {
    topNode = NULL;
    listSize = 0;
}

bool listStack::empty() {
    if (listSize == 0) {
        return true;
    }
    else {
        return false;
    }
}

int listStack::size() {
    return listSize;
}

int listStack::top() {
    if (empty()) {
        return -1;
    }
    return topNode->data;
}

void listStack::push(int data) {
    node* newNode = new node();
    newNode->data = data;
    newNode->next = topNode;
    topNode = newNode;
    listSize++;
}

void listStack::pop() {
    if (empty()) {
        return;
    }
    node* curNode = topNode;
    topNode = topNode->next;
    delete curNode;
    listSize--;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
