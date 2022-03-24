#include <iostream>
using namespace std;

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
    int rearIndex;
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

int arrayQueue::size(){
    return n;
}

int arrayQueue::front(){
    if (empty()) {
        return -1;
    }
    return  arr[frontIndex];
}

void arrayQueue::enqueue(int data) {
    if (size() == capacity) {
        return;
    }
    arr[rearIndex] = data;
    rearIndex = (rearIndex + 1) % capacity;
    n++;
}

void arrayQueue::dequeue(){
    if (empty()) {
        return;
    }
    frontIndex = (frontIndex + 1) % capacity;
    n--;
}

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
