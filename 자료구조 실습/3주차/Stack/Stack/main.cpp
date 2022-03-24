#include <iostream>
using namespace std;

struct node {
    int data;
    node* nextNode;
};

class NodeStack {
public:
    NodeStack();
    bool empty();
    int size();
    int top();
    void push(int data);
    void pop();
    
private:
    node* topNode;
    int stackSize;
};

NodeStack::NodeStack() {
    topNode = NULL;
    stackSize = 0;
}

bool NodeStack::empty() {
    if (stackSize == 0 ) {
        return true;
    } else {
        return  false;
    }
}

int NodeStack::size() {
    return stackSize;
}

int NodeStack::top() {
    if (empty()) {
        return -1;
    }
    return topNode->data;
}

void NodeStack::push(int data) {
    node* newNode = new node();
    newNode->data = data;
    newNode->nextNode = topNode;
    topNode = newNode;
    stackSize++;
}

void NodeStack::pop() {
    if (empty()) {
        return;
    }
    node* currentNode = topNode;
    topNode = topNode->nextNode;
    delete currentNode;
    stackSize--;
}


int main(int argc, const char * argv[]) {
    
    
    return 0;
}
