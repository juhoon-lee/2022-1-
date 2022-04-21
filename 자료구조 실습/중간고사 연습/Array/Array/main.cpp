#include <iostream>
using namespace std;

class Array {
public:
    Array(int sz);
    int at(int idx);
    void add(int idx, int value);
    void set(int idx, int value);
    void print();
    void remove(int idx);
private:
    int *arr;
    int arrSize;
};

Array::Array(int sz) {
    arrSize = sz;
    arr = new int[arrSize];
    for (int i = 0; i < sz; i++) {
        arr[i] = 0;
    }
}

int Array::at(int idx) {
    return arr[idx];
}

void Array::add(int idx, int value) {
    for (int i = arrSize - 2; i >= idx; i--) {
        arr[i+1] = arr[i];
    }
    arr[idx] = value;
}

void Array::set(int idx, int value) {
    arr[idx] = value;
}

void Array::print() {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Array::remove(int idx) {
    for (int i = idx + 1; i < arrSize; i++) {
        arr[i-1] = arr[i];
    }
    arr[arrSize-1] = 0;
}

int main(int argc, const char * argv[]) {
        
    return 0;
}
