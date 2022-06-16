#include <iostream>
#include <vector>
using namespace std;

class heap {
public:
    heap();
    int size();
    bool empty();
    void insert(int e);
    int min();
    void removeMin();

private:
    vector<int> arr;
    
    void swap(int idx1, int idx2);
    void upHeap(int idx);
    void downHeap(int idx);
};

heap::heap() {
    arr.push_back(0);
}

int heap::size() {
    return (int)arr.size()-1;
}

bool heap::empty() {
    return arr.size() == 1;
}

void heap::swap(int idx1, int idx2) {
    arr[0] = arr[idx1]; // temp 대신 첫 번째 원소를 쓰는군
    arr[idx1] = arr[idx2];
    arr[idx2] = arr[0];
}

void heap::insert(int e) {
    arr.push_back(e);
    upHeap(size());
}

int heap::min() {
    if (empty()) {
        return -1;
    }
    return arr[1];
}

void heap::removeMin() {
    if (empty()) {
        return;
    }
    swap(1, size());
    arr.pop_back();
    downHeap(1);
}

void heap::upHeap(int idx) {
    if (idx == 1) {
        return;
    }
    
    int parent = idx / 2;
    if (arr[parent] > arr[idx]) {
        swap(parent, idx);
        upHeap(parent);
    }
}

void heap::downHeap(int idx) {
    int left = 2 * idx;
    int right = 2 * idx + 1;
    int child;
    
    if (left > size()) {
        return;
    }
    else if (left == size()) {
        child = left;
    }
    else {
        if (arr[left] <= arr[right]) {
            child = left;
        }
        else child = right;
    }
    
    if (arr[child] < arr[idx]) {
        swap(child, idx);
        downHeap(child);
    }
}



int main() {

    return 0;
}
