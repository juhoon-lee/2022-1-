#include <iostream>
#include <string>
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
	int hashFunc(int key);
	int hashFunc2(int key);
};

hashTable::hashTable(int N, int M) {
	capacity = N;
	capacity = M;
	table = new entry[capacity];
	return;
}

int hashTable::hashFunc(int key) {
	return key % capacity;
}

int hashTable::hashFunc2(int key) {
	return divisor - (key % divisor);
}

void hashTable::put(int key, string value) {
	int index = hashFunc(key);
	int probe = 1;

	while (table[index].valid == ISITEM && probe <= capacity){
		index = hashFunc(index + hashFunc2(key));
		probe++;
	}

	if (probe > capacity) return;
	table[index] = entry(key, value);
	return;
}

void hashTable::erase(int key) {
	int index = hashFunc(key);
	int probe = 1;

	while (table[index].valid != NOITEM && probe <= capacity) {
		if (table[index].valid == ISITEM && table[index].key == key) {
			table[index].erase();
			return;
		}
		index = hashFunc(index + hashFunc2(key));
		probe++;
	}

	return;
}

string hashTable::find(int key) {
	int index = hashFunc(key);
	int probe = 1;

	while (table[index].valid != NOITEM && probe <= capacity){
		if (table[index].valid == ISITEM && table[index].key == key) {
			return table[index].value;
		}
		index = hashFunc(index + hashFunc2(key));
		probe++;
	}

	return "";
}

int main() {
	int orderCount, x;
	string order;
	
	cin >> orderCount;

	for (int i = 0; i < orderCount; i++)
	{
		cin >> order;
		if (order == "")
		{

		}
		else if (order == "")
		{

		}
		else if (order == "")
		{

		}

	}

	return 0;
}