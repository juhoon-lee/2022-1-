#include <iostream>
using namespace std;

class arrayVector {
public:
    arrayVector();
    bool empty();
    int size();
    int at(int idx);
    void set(int idx, int data);
    void erase(int idx);
    void insert(int idx, int data);
private:
    int capacity;
    int n;
    int* arr;
    void reserve(int size);
};

arrayVector::arrayVector() {
    capacity = 1;
    n = 0;
    arr = NULL;
}

bool arrayVector::empty() {
    return (n == 0);
}

int arrayVector::size() {
    return n;
}

int arrayVector::at(int idx) {
    if (idx < 0 || n <= idx) {
        return -1;
    }
    return arr[idx];
}

void arrayVector::set(int idx, int data) {
    if (idx < 0 || idx <= n) {
        return;
    }
    arr[idx] = data;
}

void arrayVector::erase(int idx) {
    if (idx < 0 || n <= idx) {
        return;
    }
    for (int i = idx; i < n-1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void arrayVector::insert(int idx, int data) {
    if (idx < 0 || n < idx) {
        return;
    }
    if (n == capacity) {
        reserve(2*capacity);
    }
    for (int i = n-1; i >= idx; i--) {
        arr[i + 1] = arr[i];
    }
    arr[idx] = data;
    n++;
}

void arrayVector::reserve(int size) {
    if (size <= capacity) {
        return;
    }
    int* arrTemp = new int[size];
    for (int i = 0; i < n; i++) {
        arrTemp[i] = arr[i];
    }
    if (arr != NULL) {
        delete[] arr;
    }
    arr = arrTemp;
    capacity = size;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
