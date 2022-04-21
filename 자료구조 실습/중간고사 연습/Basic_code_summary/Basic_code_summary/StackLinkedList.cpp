#include <iostream>
using namespace std;
// 링크드 리스트 기반 스택 -> 걍 헤드에 다 때려박으면 될듯
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

// push 연산
void listStack::push(int data) {
    node* newNode = new node(); // 새 노드
    newNode->data = data;
    newNode->next = topNode; // 위에 두 줄 그냥 생성자로 때려도 될 듯
    topNode = newNode;
    listSize++; // don't forget
}

// pop 연산
void listStack::pop() {
    if (empty()) {
        return;
    }
    node* curNode = topNode;
    topNode = topNode->next;
    delete curNode; // topNode 옮기고 삭제~
    listSize--; // don't forget
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
