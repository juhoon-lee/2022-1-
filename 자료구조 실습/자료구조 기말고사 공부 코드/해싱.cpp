#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

struct entry {
    int key;
    string value;
    int valid;
    
    entry() {
        key = 0;
        value = "";
        valid = NOITEM;
    }
    
    entry(int key, string value) {
        this->key = key;
        this->value = value;
        valid = ISITEM;
    }
    
    void erase() {
        valid = AVAILABLE;
    }
};

class hashTable { // 선형 조사법
public:
    hashTable(int N);
    void put(int key, string value);
    void erase(int key);
    string find(int key);
    
private:
    entry* table;
    int capacity;
    int hashFnc(int key);
};

hashTable::hashTable(int N) {
    capacity = N;
    table = new entry[capacity];
    return;
}

int hashTable::hashFnc(int key) {
    return key % capacity;
}

void hashTable::put(int key, string value) {
    int index = hashFnc(key);
    int probe = 1;
    while (table[index].valid == ISITEM && probe <= capacity) {
        index = hashFnc(index + 1);
        probe++;
    }
    if (probe > capacity) {
        return;
    }
    table[index] = entry(key, value);
//    return;
}

void hashTable::erase(int key) {
    int index = hashFnc(key);
    int probe = 1;
    
    while (table[index].valid != NOITEM && probe <= capacity) {
        if (table[index].valid == ISITEM && table[index].key == key) {
            table[index].erase();
            return;
        }
        index = hashFnc(index+1);
        probe++;
    }
    return;
}

string hashTable::find(int key) {
    int index = hashFnc(key);
    int probe = 1;
    
    while (table[index].valid != NOITEM && probe <= capacity) {
        if (table[index].valid == ISITEM && table[index].key == key) {
            return table[index].value;
        }
        index = hashFnc(index+1);
        probe++;
    }
    return "";
}

int main() {
    
    
    return 0;
}
