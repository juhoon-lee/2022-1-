//
//  main.cpp
//  problem1
//
//  Created by 이주훈 on 2022/03/11.
//

#include <iostream>
#include <string>
using namespace std;



struct node {
    int data;
    node* nextNode = NULL;
};

class singlelyLinkedList {
public:
    singlelyLinkedList();
    bool empty();
    void appendNode(int data);
    void insertNode(int index, int data);
    int deleteNode(int index);
    void printNode();
    void min();

private:
    node* head;
    node* tail;
    int listSize;
};

singlelyLinkedList::singlelyLinkedList() {
    head = NULL;
    tail = NULL;
    listSize = 0;
}

bool singlelyLinkedList::empty() {
    if (listSize == 0) {
        return true;
    }
    else {
        return false;
    }
}

void singlelyLinkedList::appendNode(int data) {

    node* newNode = new node;
    newNode->data = data;
    newNode->nextNode = NULL;

    if (empty())
    {
        head = tail = newNode;
    }
    else {
        tail->nextNode = newNode;
        tail = newNode;
    }
    listSize++;

    printNode();
}

void singlelyLinkedList::insertNode(int index, int data) {
    if (index < 0 || index > listSize) {
        cout << "Index Error" << endl;
        return;
    }
    else if (index == listSize)
    {
        appendNode(data);
    }
    else if (index == 0)
    {
        node* newNode = new node;
        newNode->data = data;
        newNode->nextNode = head;
        head = newNode;
        listSize++;
        printNode();
    }
    else {
        node* newNode = new node;
        newNode->data = data;
        node* currentNode = head;
        for (int i = 0; i < index - 1; i++)
        {
            currentNode = currentNode->nextNode;
        }
        newNode->nextNode = currentNode->nextNode;
        currentNode->nextNode = newNode;
        listSize++;
        printNode();
    }
    
}

int singlelyLinkedList::deleteNode(int index) {
    int returnData = 0;

    if (empty() || index < 0 || index >= listSize)
    {
        return -1;
    }

    node* currentNode = head;
    returnData = head->data;
    if (index == 0)
    {
        if (listSize == 1) {
            head = tail = NULL;
        }
        else {
            head = head->nextNode;
        }
    }
    else {
        node* prevNode = head;
        for (int i = 0; i < index; i++)
        {
            prevNode = currentNode;
            currentNode = currentNode->nextNode;
        }
        prevNode->nextNode = currentNode->nextNode;
        if (currentNode == tail) {
            tail = prevNode;
        }
    }

    returnData = currentNode->data;
    delete currentNode;
    listSize--;

    return returnData;
}

void singlelyLinkedList::printNode() {
    if (empty())
    {
        cout << "empty" << endl;
        return;
    }
    node* currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->data << " ";
        currentNode = currentNode->nextNode;
    }
    cout << endl;
}

void singlelyLinkedList::min() {
    if (empty())
    {
        cout << "empty" << endl;
        return;
    }

    node* currentNode = head;
    int min = currentNode->data;
    while (currentNode != NULL)
    {
        if (min > currentNode->data){
            min = currentNode->data;
        }
        currentNode = currentNode->nextNode;
    }
    cout << min << endl;
}


int main(int argc, const char * argv[]) {
    
    singlelyLinkedList linkedList;

    int orderCount = 0;
    string order = "";

    cin >> orderCount;

    for (int i = 0; i < orderCount; i++)
    {
        cin >> order;
        if (order == "Print"){
            linkedList.printNode();
        }
        else if (order == "Append") {
            int data = 0;
            cin >> data;
            linkedList.appendNode(data);
        }
        else if (order == "Delete") {
            int index = 0;
            cin >> index;
            cout << linkedList.deleteNode(index) << endl;
        }
        else if (order == "Insert") {
            int index = 0;
            int data = 0;
            cin >> index >> data;
            linkedList.insertNode(index, data);
        }
        else if (order == "Min") {
            linkedList.min();
        }
    }

    return 0;
}

