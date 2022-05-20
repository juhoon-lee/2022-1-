#include <iostream>
#include <string>
using namespace std;

#define NOUSER 0
#define LOGIN 1
#define LOGOUT 2

struct entry {
	string key;
	string value;
	int valid;

	entry() {
		key = "";
		value = "";
		valid = NOUSER;
	}

	entry(string key, string value) {
		this->key = key;
		this->value = value;
		valid = LOGOUT;
	}

	void login() {
		valid = LOGIN;
	}

	void logout() {
		valid = LOGOUT;
	}
};

class hashTable {
public:
	hashTable(int N);
	void signup(string key, string value);
	void login(string key, string value);
	void logout(string key);

private:
	entry* table;
	int capacity;
	int hashFunc(int key);
	int stringToInt(string key);
};

hashTable::hashTable(int N) {
	capacity = N;
	table = new entry[capacity];
	return;
}

int hashTable::hashFunc(int key) {
	return key % capacity;
}

int hashTable::stringToInt(string key) {
	int result = 0;
	for (int i = 0; i < key.size(); i++)
	{
		result += result + ((int)key[i] * 26 * i);
	}
	return result;
}

void hashTable::signup(string key, string value) {
	int index = hashFunc(stringToInt(key));
	int probe = 1;
	int count = 0;

	while (count < capacity){
		if (table[index].valid == NOUSER)
		{
			table[index] = entry(key, value);
			cout << "Submit" << endl;
			return;
		}
		else if (table[index].key == key)
		{
			cout << "Invalid" << endl;
			return;
		}
		probe++;
		index = hashFunc(index + 1);
		count++;
	}

	table[index] = entry(key, value);
	return;
}

void hashTable::login(string key, string value) {
	int index = hashFunc(stringToInt(key));
	int probe = 1;
	int count = 0;

	while (count < capacity) {
		if (table[index].valid == NOUSER)
		{
			cout << "Invalid" << endl;
			return;
		}
		else if (table[index].key == key && table[index].value != value)
		{
			cout << "Invalid" << endl;
			return;
		}
		else if (table[index].key == key && table[index].value == value && table[index].valid == LOGIN)
		{
			cout << "Quit" << endl;
			return;
		}
		else if (table[index].key == key && table[index].value == value && table[index].valid == LOGOUT)
		{
			table[index].login();
			cout << "Submit" << endl;
			return;
		}
		probe++;
		count++;
		index = hashFunc(index + 1);
	}

	table[index] = entry(key, value);
	return;
}

void hashTable::logout(string key) {
	int index = hashFunc(stringToInt(key));
	int probe = 1;
	int count = 0;

	while (count < capacity) {
		if (table[index].valid == NOUSER)
		{
			return;
		}
		else if (table[index].key == key)
		{
			table[index].logout();
			cout << "Submit" << endl;
			return;
		}
		index = hashFunc(index + 1);
		count++;
	}
	return;
}

int main() {

	int orderCount;
	string order, key, value;

	cin >> orderCount;
	hashTable ht = hashTable(500000);

	for (int i = 0; i < orderCount; i++)
	{
		cin >> order;
		if (order == "signup")
		{
			cin >> key >> value;
			ht.signup(key, value);
		}
		else if (order == "login")
		{
			cin >> key >> value;
			ht.login(key, value);
		}
		else if (order == "logout")
		{
			cin >> key;
			ht.logout(key);
		}
	}

	return 0;
}