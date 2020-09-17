
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <list>
using namespace std;
class HashMap {
private:
	static const int hashSize = 10;
	list<pair<string, string>>table[hashSize];
public:
	void insertion(string key, string value);
	void deletion(string key);
	string searchByKey(string key);
	bool isKeyExist(string key);
	int hashFunction(string key);
	bool isEmpty();
    void printHash();
};
bool HashMap::isEmpty() {
	for (int i = 0; i < hashSize; i++) {
		if (table[i].size() != 0) return false;
	}
	return true;
}
int HashMap::hashFunction(string key) {
	int hashValue = 0;
	for (auto i : key)
		hashValue += i;
	return hashValue % hashSize;
}
bool HashMap::isKeyExist(string key) {
	int hashValue = hashFunction(key);
	auto itr = table[hashValue].begin();
	for (; itr != table[hashValue].end(); itr++) {
		if (itr->first == key) return true;
	}
	return false;
}
void HashMap::insertion(string key, string value) {
    if (isKeyExist(key)) {
        cout << "Key Already Exists!\n";
        return;
    }
	int hashValue = hashFunction(key); //4
	table[hashValue].push_back({ key,value });
    cout <<  "Insertion Complete!\n";
}
void HashMap::deletion(string key) {
	if (!isKeyExist(key)) {
		cout << "Key Does not Exist!!\n";
	}
	int hashValue = hashFunction(key); //4
	auto itr = table[hashValue].begin();
	for (; itr != table[hashValue].end(); itr++) {
		if (itr->first == key) {
			table[hashValue].erase(itr);
			cout << "Deleted Successfully\n";
			return;
		}
	}
}
string HashMap::searchByKey(string key) {
	if (!isKeyExist(key)) {
		return "There is no Matched Key!!";
	}
	int hashValue = hashFunction(key); //4
	auto itr = table[hashValue].begin();
	for (; itr != table[hashValue].end(); itr++) {
		if (itr->first == key) {
			return itr->second;
		}
	}
}
void HashMap::printHash() {
    cout << "--------------------------------------\n";
    for (int i = 0; i < hashSize; i++) {
        auto itr = table[i].begin();
        cout << i << "| ";
        while (itr != table[i].end()) {
            cout << "[" << itr->first << "," << itr->second << "] -> ";
            itr++;
        } cout << "\n";
    }
}

int main()
{
    HashMap H; 
    int option;
    string key, value;
    do {
        cout << "\nWhat operation do you want to perform? Select Option Number. Enter 0 to exit" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete By Key" << endl;
        cout << "3. Search By Key" << endl;
        cout << "4. Print HashMap" << endl;
        cout << "5. Clear System" << endl;
        cout << "0. Exist" << endl;

        cin >> option;
        
        //Node n1;

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "Enter Key and Value to Insert" << endl;
            cin >> key;
            cin >> value;
            H.insertion(key, value);
            cout << "\n";
            
            break;
        case 2:
            cout << "Enter Key which you want to delete" << endl;
            cin >> key;
            H.deletion(key);
            cout << "\n";
            break;
        case 3:
            cout << "Enter Key to look up its Value" << endl;
            cin >> key;
            cout<< H.searchByKey(key)<<"\n";
            break;

        case 4:
            H.printHash();
            break;

        case 5:
            system("cls");
            break;
        default:
            cout << "Enter proper option number" << endl;

        }
    } while (option != 0);
}

