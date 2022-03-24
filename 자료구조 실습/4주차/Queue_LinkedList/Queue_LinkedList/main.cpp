#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class listQueue {
public:
    listQueue();
    bool empty();
    int size();
    int front();
    void enqueue(int data);
    void dequeue();
    
private:
    node* frontNode;
    node* rearNode;
    int n;
};

listQueue::listQueue() {
    frontNode = NULL;
    rearNode = NULL;
    n = 0;
}

bool listQueue::empty() {
    return (n ==0 );
}

int listQueue::size() {
    return n;
}

int listQueue::front() {
    if (empty()) {
        return -1;
    }
    return  frontNode->data;
}

void listQueue::enqueue(int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    if (empty()) {
        frontNode = rearNode = newNode;
    }
    else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    n++;
}

void listQueue::dequeue() {
    if (empty()) {
        return;
    }
    
    node* currentNode = frontNode;
    if (size() == 1) {
        frontNode = rearNode = NULL;
    }
    else {
        frontNode = frontNode->next;
    }
    delete currentNode;
    n--;
}


int main(int argc, const char * argv[]) {
    
    
    return 0;
}
