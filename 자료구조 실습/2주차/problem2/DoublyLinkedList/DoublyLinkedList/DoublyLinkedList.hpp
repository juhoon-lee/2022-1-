//
//  DoublyLinkedList.hpp
//  DoublyLinkedList
//
//  Created by 이주훈 on 2022/03/15.
//

#ifndef DLL
#define DLL

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * prevNode = NULL;
    Node * nextNode = NULL;
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

#endif
