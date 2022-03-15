//
//  main.cpp
//  DoublyLinkedList
//
//  Created by 이주훈 on 2022/03/15.
//


#include <iostream>
#include <string>
//#include "DoublyLinkedList.hpp"
using namespace std;

struct Node {
    int data;
    Node* prevNode = NULL;
    Node* nextNode = NULL;
};

class DoublyLinkedList {
public:
    DoublyLinkedList();
    void print();
    void append(int);
    int deleteNode(int);
    void printReverse();
    void update(int,int);

private:
    int nodeCount = 0;
    Node* head;
    Node* tail;
};

DoublyLinkedList::DoublyLinkedList(){
    this->head = NULL;
    this->tail = NULL;
}

void DoublyLinkedList::print() {
    if (nodeCount == 0) {
        cout << "empty" << endl;
        return;
    }
    Node* currentNode = head;
    while (currentNode != NULL) {
        cout << currentNode->data << " ";
        
        currentNode = currentNode->nextNode;
    }
    cout << endl;
}

void DoublyLinkedList::append(int x) {
    if (nodeCount == 0) {
        Node* newNode = new Node;
        newNode->data = x;
        this->head = this->tail = newNode;
        newNode->prevNode = NULL;
        newNode->nextNode = NULL;
        this->nodeCount += 1;
        this->print();
        return;
    }
    
    Node* currentNode = head;
    for (int i = 0; i < nodeCount-1; i++) {
        currentNode = currentNode->nextNode;
    }
    
    Node* newNode = new Node;
    newNode->data = x;
    currentNode->nextNode = newNode;
    newNode->prevNode = currentNode;
    newNode->nextNode = NULL;
    this->tail = newNode;
    this->nodeCount += 1;
    print();
}

int DoublyLinkedList::deleteNode(int index){
    
    if (index >= nodeCount || nodeCount == 0) {
        return -1;
    }
    
    Node* currentNode = head;
    int returnData = head->data;
    if (index == 0)
    {
        if (nodeCount == 1) {
            head = tail = NULL;
        }
        else {
            head = head->nextNode;
            head->prevNode = NULL;
        }
    }
    else {
        for (int i = 0; i < index; i++)
        {
            currentNode = currentNode->nextNode;
        }
        currentNode->prevNode->nextNode = currentNode->nextNode;
        if (currentNode == tail) {
            tail = currentNode->prevNode;
        }
        else{
            currentNode->nextNode->prevNode = currentNode->prevNode;
        }
    }

    returnData = currentNode->data;
    delete currentNode;
    nodeCount--;

    return returnData;
}

void DoublyLinkedList::printReverse() {
    if (nodeCount == 0) {
        cout << "empty" << endl;
        return;
    }
    Node* currentNode = tail;
    while (currentNode != NULL) {
        cout << currentNode->data << " ";
        currentNode = currentNode->prevNode;
    }
    cout << endl;
}

void DoublyLinkedList::update(int x, int y) {
    if (nodeCount == 0) {
        cout << "empty" << endl;
        return;
    }
    Node* currentNode = head;
    bool check = false;
    while (currentNode != NULL) {
        if (currentNode->data == x) {
            currentNode->data = y;
        }
        currentNode = currentNode->nextNode;
    }
    if (check) {
        cout << "Not found" << endl;
        return;
    }
    this->print();
}


int main(int argc, const char * argv[]) {
    
    DoublyLinkedList DoubleList;
    int orderCount = 0;
    string order = "";
    cin >> orderCount;
    
    for (int i = 0; i < orderCount; i++) {
        cin >> order;
        
        if (order == "Print") {
            DoubleList.print();
        }
        else if (order == "Append") {
            int x = 0;
            cin >> x;
            DoubleList.append(x);
        }
        else if (order == "Delete") {
            int x = 0;
            cin >> x;
            cout << DoubleList.deleteNode(x) << endl;
        }
        else if (order == "Print_reverse")  {
            DoubleList.printReverse();
        }
        else if (order == "Update")  {
            int x,y = 0;
            cin >> x >> y;
            DoubleList.update(x, y);
        }
    }
    cout << endl;
    return 0;
}

