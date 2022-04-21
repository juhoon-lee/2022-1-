#include <iostream>
using namespace std;

// 배열 기반 스택
class arrayStack {
public:
    arrayStack(int capacity);
    bool empty();
    int size();
    int top();
    void push(int data);
    void pop();
    
private:
    int* arr; // 이래야 동적으로 할당 받을 수 있겠네..
    int capacity;
    int topIndex;
};

// 해당 사이즈 만큼 배열 할당
arrayStack::arrayStack(int capacity) {
    this->capacity = capacity;
    arr = new int[capacity];
    topIndex = -1;
}

// 스택이 비었으면~ true
bool arrayStack::empty() {
    if (topIndex == -1) { // 초기값 -1
        return true;
    }
    else {
        return false;
    }
}

// stack Size 출력(값이 인덱스보다 하나 더 많다)
int arrayStack::size() {
    return topIndex + 1;
}

// top에 있는것 출력
int arrayStack::top() {
    if (empty()) {
        return -1;
    }
    return arr[topIndex];
}

// 값 넣기
void arrayStack::push(int data) {
    if (size() == capacity) { // 최대치면 리턴 capacity-1 이어도 인정.
        return;
    }
    arr[++topIndex] = data; // 인덱스 추가해서 넣기
}

// 값 제거
void arrayStack::pop() {
    if (empty()) {
        return;
    }
    topIndex--; // 간단~
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
