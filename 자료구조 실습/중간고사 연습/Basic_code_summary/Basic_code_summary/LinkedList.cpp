#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class singlyLinkedList {
public:
    singlyLinkedList();
    bool empty();
    void append(int data);
    void insertion(int idx, int data);
    void deletion(int idx);
    void print();
    
private:
    node* head;
    node* tail;
    int listSize;
};

// 단일 링크드 리스트 생성자
singlyLinkedList::singlyLinkedList() {
    head = NULL;
    tail = NULL;
    listSize = 0;
}

// 비었으면 true 아니면 false
bool singlyLinkedList::empty() {
    if (listSize == 0) {
        return true;
    }
    else {
        return false;
    }
}

// 새 노드를 만들어서 링크드 리스트 가장 뒤에 추가
void singlyLinkedList::append(int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL; // 이건 node 생성자를 만들어서 해결 할 수도 있긴 하겠다.
    
    if (empty()) { // 비었으면 head == tail == 새로운 노드
        head = tail = newNode;
    }
    else { // 아니라면 tail의 다음 노드는 새로운 노드 -> tail을 마지막 노드로 변경.
        tail->next = newNode;
        tail = newNode;
    }
    listSize++; // 까먹기 쉬우니 잊지 말자
}

// 중간에 삽입
void singlyLinkedList::insertion(int idx, int data) {
    if (idx < 0 || idx > listSize) { // 인덱스가 0보다 작거나 linkedList보다 크다면 반환
        return;
    }
    else if (idx == listSize) { // 마지막에 삽입이라면 append 하자
        append(data);
    }
    else if (idx == 0) { // head에 삽입이라면 추가하고 head만 옮겨주기
        node* newNode = new node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        listSize++;
    }
    else { // 중간이라면 중간 만큼 이동하고 삽입 -> 역기서는 인덱스 바로 전으로 가서 삽입했다.(단일이면 이게 나은듯)
        node* newNode = new node;
        newNode->data = data;
        node* curNode = head;
        for (int i = 0; i < idx-1; i++) {
            curNode = curNode->next;
        }
        newNode->next = curNode->next;
        curNode->next = newNode;
        listSize++;
    }
}

// 삭제연산: 빈배열,인덱스x 이면 리턴, 노드 두개를 설정해 임시로 배정해주고 연결
void singlyLinkedList::deletion(int idx) {
    if (empty() || idx < 0 || idx >= listSize) {
        return;
    }
    
    node* curNode = head;
    if (idx == 0) {
        if (listSize == 1) {
            head = tail = NULL;
        }
        else {
            head = head->next;
        }
    }
    else {
        node* preNode = head;
        for (int i = 0; i < idx; i++) {
            preNode = curNode;
            curNode = curNode->next;
        }
        preNode->next = curNode->next;
        if (curNode == tail) {
            tail = preNode;
        }
    }
    delete curNode;
    listSize--;
}

// 전체를 순회하면서 출력 (tail 이후는 NULL)
void singlyLinkedList::print() {
    if (empty()) {
        cout << "empty";
    }
    node* curNode = head;
    while (curNode != NULL) {
        cout << curNode->data << " ";
        curNode = curNode->next;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
