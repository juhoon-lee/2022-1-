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

// 배열 생성자 -> 사이즈를 주면 사이즈 만큼 배열으 생성 및 0으로 초기화
Array::Array(int sz) {
    arrSize = sz;
    arr = new int[arrSize];
    for (int i = 0; i < sz; i++) {
        arr[i] = 0;
    }
}

// 인덱스 해당 원소 반환
int Array::at(int idx) {
    return arr[idx];
}

// 인덱스에 값 추가
void Array::add(int idx, int value) {
    for (int i = arrSize - 2; i >= idx; i--) { // 끝에서 부터 하나씩 이동시키고 값 삽입(안전하게 n-1까지만 사용)
        arr[i+1] = arr[i];
    }
    arr[idx] = value;
}

// 값 세팅
void Array::set(int idx, int value) {
    arr[idx] = value;
}

// 배열 전체 값 출력
void Array::print() {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 값을 제거하고
void Array::remove(int idx) {
    for (int i = idx + 1; i < arrSize; i++) {
        arr[i-1] = arr[i];
    }
    arr[arrSize-1] = 0; // 이건 없어도 괜찮지 않나?
}

int main(int argc, const char * argv[]) {
        
    return 0;
}
