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

class hashTable {
public:
    hashTable(int N, int M);
    void put(int key, string value);
    void erase(int key);
    string find(int key);
    
private:
    entry* table;
    int capacity;
    int divisor;
    int hashFnc(int key);
    int hashFnc2(int key);
};

hashTable::hashTable(int N, int M) {
    capacity = N;
    divisor = M;
    table = new entry[capacity];
    return;
}

int hashTable::hashFnc(int key) {
    return key % capacity;
}

int hashTable::hashFnc2(int key) {
    return divisor - (key & divisor);
}

void hashTable::put(int key, string value) {
    int index = hashFnc(key);
    int probe = 1;
    
    while (table[index].valid == ISITEM && probe <= capacity) {
        index = hashFnc(index + hashFnc2(key));
        probe++;
    }
    
    if (probe > capacity) {
        return;
    }
    table[index] = entry(key, value);
}

void hashTable::erase(int key) {
    int index = hashFnc(key);
    int probe = 1;
    
    while (table[index].valid != NOITEM && probe <= capacity) {
        if (table[index].valid == ISITEM && table[index].key == key) {
            table[index].erase();
            return;
        }
        index = hashFnc(index + hashFnc2(key));
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
        index = hashFnc(index + hashFnc2(key));
        probe++;
    }
    return "";
}

int main() {
    
    
    return 0;
}
