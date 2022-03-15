//
//  main.cpp
//  LinkedList
//
//  Created by 이주훈
//

#include <iostream>
using namespace std;

// 노드 구현
struct node {
    int element = 0;
    node * next;
};

// 링크드 리스트 객체
class LinkedList {
    int size; // size는 필요하지 않다면 없어도 되겠지만 있는게 더 좋겠군.
    node* head;
    node* tail;
    
public:
    LinkedList() {
        size = 0;
        head = NULL;
        tail = NULL;
    };
};


int main(int argc, const char * argv[]) {
    
    LinkedList a;
   
    
    return 0;
}
