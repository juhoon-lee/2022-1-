//
//  DoublyLinkedList.cpp
//  DoublyLinkedList
//
//  Created by 이주훈 on 2022/03/15.
//

#include "DoublyLinkedList.hpp"

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
    
    if (index >= nodeCount) {
        return -1;
    }
    
    Node* currentNode = head;
    for (int i = 0; i < index; i++) {
        currentNode = currentNode->nextNode;
    }
    
    currentNode->prevNode->nextNode = currentNode->nextNode;
    currentNode->nextNode->prevNode = currentNode->prevNode;
    int data = currentNode->data;
    delete currentNode;
    nodeCount -= 1;
    return data;
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
