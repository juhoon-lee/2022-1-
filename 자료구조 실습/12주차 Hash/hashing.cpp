#include <iostream>
#include <string>
using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

struct entry{
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
	hashTable(int N);
	void put(int key, string value);
	void erase(int key);
	void vacant();
	string find(int key);

private:
	entry* table;
	int capacity;
	int hashFunc(int key);
};

hashTable::hashTable(int N) {
	capacity = N;
	table = new entry[capacity];
	return;
}

int hashTable::hashFunc(int key) {
	return key % capacity;
}

void hashTable::put(int key, string value) {
	int index = hashFunc(key);
	int probe = 1;

	while (table[index].valid == ISITEM && probe <= capacity){
		index = hashFunc(index + 1);
		probe++;
	}
	
	cout << probe << endl;

	if (probe > capacity) return;
	table[index] = entry(key, value);
	return;
}

void hashTable::erase(int key) {
	int index = hashFunc(key);
	int probe = 1;

	while (table[index].valid != NOITEM && probe <= capacity){
		if (table[index].valid == ISITEM && table[index].key == key)
		{
			cout << table[index].value << endl;
			table[index].erase();
			return;
		}
		index = hashFunc(index + 1);
		probe++;
	}

	cout << "None" << endl;
	return;
}

string hashTable::find(int key) {
	int index = hashFunc(key);
	int probe = 1;

	while (table[index].valid != NOITEM && probe <= capacity)
	{
		if (table[index].valid == ISITEM && table[index].key == key) {
			cout << table[index].value << endl;
			return "";
		}
		index = hashFunc(index + 1);
		probe++;
	}

	cout << "None" << endl;
	return "";
}

void hashTable::vacant() {
	int count = 0;
	for (int i = 0; i < capacity; i++)
	{
		if (table[i].valid == NOITEM || table[i].valid == AVAILABLE)
		{
			count++;
		}
	}
	cout << count << endl;
}

int main() {

	int N;
	int orderCount, key;
	string order, value;

	cin >> orderCount >> N;
	hashTable ht = hashTable(N);

	for (int i = 0; i < orderCount; i++)
	{
		cin >> order;
		if (order == "put")
		{
			cin >> key >> value;
			ht.put(key,value);
		}
		else if (order == "erase")
		{
			cin >> key;
			ht.erase(key);
		}
		else if (order == "find")
		{
			cin >> key;
			ht.find(key);
		}
		else if (order == "vacant")
		{
			ht.vacant();
		}
	}

	return 0;
}