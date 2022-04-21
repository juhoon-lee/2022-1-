#include <iostream>
using namespace std;
// 배열 기반 큐
class arrayQueue {
public:
    arrayQueue(int capacity);
    bool empty();
    int size();
    int front();
    void enqueue(int data);
    void dequeue();
    
private:
    int* arr;
    int capacity;
    int frontIndex;
    int rearIndex; // 아니 여기선 마지막 원소 다음이 아니라 마지막 원소의 인덱스로 구현했네..
    int n;
};

arrayQueue::arrayQueue(int capacity) { 
    this->capacity = capacity;
    arr = new int[capacity];
    frontIndex = rearIndex = 0;
    n = 0;
}

bool arrayQueue::empty() {
    return (n == 0);
}

int arrayQueue::size() {
    return n;
}

int arrayQueue::front() {
    if (empty()) {
        return -1;
    }
    return arr[frontIndex];
}

void arrayQueue::enqueue(int data) {
    if (size() == capacity) {
        return;
    }
    arr[rearIndex] = data;
    rearIndex = (rearIndex + 1) % capacity;
    n++;
}

void arrayQueue::dequeue() {
    if (empty()) {
        return;
    }
    frontIndex = (frontIndex + 1) % capacity;
    n--;
}

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
