#include <iostream>
using namespace std;
// 이중 링크드 리스트로 구현된 List 자료구조..

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
    void nextP();
    void prevP();
    void print();
    void find(int data);
    
private: // 왜 헤더 트레일러로 했을까 head tail로 하면 통일성 있는데..
    node* header;
    node* trailer;
    node* curPos;
    int n;
};

nodeList::nodeList() {
    header = new node();
    trailer = new node();
    header->next = trailer;
    trailer->prev = header;
    header->prev = trailer->next = NULL;
    curPos = begin();
}

bool nodeList::empty() {
    return (n == 0);
}

int nodeList::size() {
    return n;
}

node* nodeList::begin() {
    curPos = header->next;
    return header->next;
}

node* nodeList::end() {
    curPos = trailer;
    return trailer;
}

void nodeList::insert(node *pos, int data) {
    node* newNode = new node();
    newNode->data = data;
    newNode->prev = pos->prev;
    newNode->next = pos;
    pos->prev->next = newNode;
    pos->prev = newNode;
    n++;
}

void nodeList::insertFront(int data) {
    insert(begin(), data);
}

void nodeList::insertBack(int data) {
    insert(end(), data);
}

void nodeList::erase(node *pos){
    if (pos == trailer) {
        cout << "Empty" << endl;
        return;
    }
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    delete pos;
    n--;
}

void nodeList::eraseFront() {
    erase(begin());
}

void nodeList::eraseBack() {
    erase(end()->prev);
}

void nodeList::nextP() {
    if (curPos == trailer) {
        return;
    }
    curPos = curPos->next;
}

void nodeList::prevP() {
    if (curPos == header->next) {
        return;
    }
    curPos = curPos->prev;
}

void nodeList::print() {
    if (n == 0) {
        cout << "Empty" << endl;
    }
    node* curNode = begin();
    while (curNode != trailer) {
        cout << curNode->data << " ";
        curNode = curNode->next;
    }
    cout << endl;
}

void nodeList::find(int data) {
    int index = 0;
    bool check = false;
    node* curNode = begin();
    while (curNode != trailer) {
        if (curNode->data == data) {
            cout << index << " ";
        }
        index++;
        curNode = curNode->next;
        check = true;
    }
    if (!check) {
        cout << -1 << endl;
    }
}

// 전역변수


int main(int argc, const char * argv[]) {
    nodeList a = nodeList();
    node* pos = a.begin();
    
    int oc,x;
    string order;
    
    cin >> oc;
    for (int i = 0; i < oc; i++) {
        cin >> order;
        if (order == "begin") {
            pos = a.begin();
        }
        else if (order == "end") {
            pos = a.end();
        }
        else if (order == "insert"){
            cin >> x;
            a.insert(pos, x);
        }
        else if (order == "erase") {
            a.erase(pos);
        }
        else if (order == "nextP") {
            a.nextP();
        }
        else if (order == "prevP") {
            a.prevP();
        }
        else if (order == "print") {
            a.print();
        }
        else if(order == "find") {
            cin >> x;
            a.find(x);
        }
    }
    
    return 0;
}

