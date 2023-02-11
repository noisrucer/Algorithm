#include <iostream>
#include <list>

using namespace std;

class HashTable {
private:
	static const int hashGroups = 10;
	list<pair<int, string>> table[hashGroups];

public:
	bool isEmpty() const;
	int hashFunction(int key);
	void insertItem(int key, string value);
	void removeItem(int key);
	void searchTable(int key);
	void printTable();
	void printTableByhashValue(int hashValue);
};

bool HashTable::isEmpty() const {
	int sum{};
	for (int i = 0; i < hashGroups; i++) {
		sum += table[i].size();
	}
	if (sum == 0) return true;
	else return false;
}

int HashTable::hashFunction(int key) {
	return key % hashGroups; //key:905, in return, spit out 5.
}
void HashTable::insertItem(int key, string value) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr->second = value;
			cout << "[WARNING] key Exists and Value Replaced" << endl;
			break;
		}
	}
	if (!keyExists) {
		cell.emplace_back(key, value);
	}
	return;
}
void HashTable::searchTable(int key) {
	int hashValue = hashFunction(key);
	//hashValue = 4
	auto bItr = table[hashValue].begin();
	for (; bItr != table[hashValue].end(); bItr++) {
		if (bItr->first == key) {
			cout << "Hey I found the key! And the Value is " << bItr->second << endl;
		}
	}
}
void HashTable::printTableByhashValue(int hashValue) {
	
	//hashValue = 4
	auto bItr = table[hashValue].begin();
	for (; bItr != table[hashValue].end(); bItr++) {
		cout << bItr->second << " ";
	}
	cout << endl;
}

void HashTable::removeItem(int key) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr = cell.erase(bItr);// erase will return the pointer next to erased node
			cout << "[INFO] Item Removed." << endl;
			break;
		}
	}
	if (!keyExists) {
		cout << "[WARNING} Item Not Found" << endl;
	}
	return;
}

void HashTable::printTable() {
	for (int i{}; i < hashGroups; i++) {
		if (table[i].size() == 0) continue;
		cout << i << ": ";
		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			cout << bItr->second << ", ";

		}cout << endl;
	}
	return;
}
int main() {
	HashTable HT;
	if(HT.isEmpty()){
		cout << "Correct Answer, Good job"<<endl;
	}
	else {
		cout << "We have a prblem here" << endl;
	}

	HT.insertItem(905, "Jim");
	HT.insertItem(805, "Tom");
	HT.insertItem(705, "Bob");
	HT.insertItem(706, "Jason"); HT.insertItem(123, "Adam");
	HT.insertItem(501, "Ally");
	HT.insertItem(524, "Johnson");
	HT.insertItem(992, "Sex");

	HT.insertItem(904, "Sally");
	HT.insertItem(907, "Sandy");
	HT.insertItem(909, "Barb");
	HT.insertItem(908, "Rob");
	HT.insertItem(808, "Rick");
	HT.insertItem(908, "ROBBYROBBY");
	HT.searchTable(909);
	HT.printTableByhashValue(5);
	cout << "\n";

	HT.printTable();

	HT.removeItem(902);
	HT.removeItem(100);
	
	if (HT.isEmpty()) {
		cout << "Ohoh we have a problem" << endl;
	}
	else {
		cout << "Goob job correct answer bro!" << endl;
	}
	return 0;
}