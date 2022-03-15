//
//  main.cpp
//  1주차 배열 Linked list
//
//  Created by 이주훈 on 2022/03/04.
//

#include <iostream>
using namespace std;

class Array {
    
private:
    int *arr; // 배열
    int arrSize;
    
public:
    
    // 생성자인가?
    Array(int size) {
        this->arrSize = size;
        this->arr = new int [arrSize];
        for (int i = 0; i < arrSize ; i++) {
            arr[i] = 0;
        }
    }
    
    int at(int idx) {
        return arr[idx];
    }
    
    void add(int index, int value){
        for (int i = arrSize - 2; i >= index; i--) {
            arr[i+1] = arr[i];
        }
        arr[index] = value;
    }
    
    void set(int index, int value) {
        arr[index] = value;
    }
    
    void print(){
        for (int i = 0 ; i < arrSize; i ++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    void remove(int index){
        for (int i = index; i < arrSize; i++) {
            arr[index] = arr[index + 1];
        }
        arr[arrSize-1] = 0;
    }
};

int main(int argc, const char * argv[]) {
    Array a(5);
    
    a.print();
    a.set(4, 4);
    a.print();
    a.remove(4);
    a.print();
    
    return 0;
}
