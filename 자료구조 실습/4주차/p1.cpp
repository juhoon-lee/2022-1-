#include <iostream>
#include <string>
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
    void front();
    void rear();
    void enqueue(int data);
    void dequeue();

private:
    node* frontNode;
    node* rearNode;
    int nodeCount;
};

listQueue::listQueue() {
    frontNode = NULL;
    rearNode = NULL;
    nodeCount = 0;
}

bool listQueue::empty() {
    return (nodeCount == 0);
}

int listQueue::size() {
    return nodeCount;
}

void listQueue::front() {
    if (empty()) {
        cout << "Empty" << endl;
        return;
    }
    cout << frontNode->data << endl;
}

void listQueue::rear() {
    if (empty()) {
        cout << "Empty" << endl;
        return;
    }
    cout << rearNode->data << endl;
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
    nodeCount++;
}

void listQueue::dequeue() {
    if (empty()) {
        cout << "Empty" << endl;
        return;
    }

    node* currentNode = frontNode;
    int temp = frontNode->data;
    if (size() == 1) {
        frontNode = rearNode = NULL;
    }
    else {
        frontNode = frontNode->next;
    }
    delete currentNode;
    nodeCount--;

    cout << temp << endl;
}


int main() {
    listQueue queue = listQueue();
 
    int orderCount = 0;
    string order = "";

    cin >> orderCount;
    
    for (int i = 0; i < orderCount; i++)
    {
        cin >> order;
        if (order == "size")
        {
            cout << queue.size() << endl;
        }
        else if (order == "isEmpty")
        {
            if (queue.empty())
            {
                cout << "True" << endl;
            }
            else {
                cout << "False" << endl;
            }
        }
        else if (order == "dequeue")
        {
            queue.dequeue();
        }
        else if (order == "enqueue")
        {
            int data = 0;
            cin >> data;
            queue.enqueue(data);
        }
        else if (order == "front")
        {
            queue.front();
        }
        else if (order == "rear")
        {
            queue.rear();
        }
    }

    return 0;
}