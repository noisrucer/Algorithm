
#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    static const int hashGroups = 10;
    list<pair<string, string>>table[hashGroups];
public:
    bool isEmpty();
    int hashFunction(string key);
    void insertItem(string key, string value);
    void deleteItem(string key);
    bool isKeyExist(string key);
    void printTable();
    string searchUniversity(string key);
};
bool HashTable::isEmpty() {
    int sum = 0;
    for (int i = 0; i < hashGroups; i++) {
        sum += table[i].size();
    }
    if (sum == 0) return true;
    else return false;
}
int HashTable::hashFunction(string key) {
    int hashSum = 0;
    for (int i = 0; i < key.length(); i++) {
        hashSum += (int)key[i];
    }
    return hashSum % hashGroups; //4
}

bool HashTable::isKeyExist(string key) {
    int hashValue = hashFunction(key); //hashValue = 4;
    auto itr = table[hashValue].begin();
    for (; itr != table[hashValue].end(); itr++) {
        if (itr->first == key) {
            return true;
        }
    }
    return false;
}
void HashTable::insertItem(string key, string value) {
    if (isKeyExist(key)) { cout << key << " already exists!!!" << endl; return; }
    
        int hashValue = hashFunction(key);
       
        //if there is no key existing , then go ahead input
        table[hashValue].emplace_back(key, value);
    

}
void HashTable::deleteItem(string key) {
    int hashValue = hashFunction(key);
    if (!isKeyExist(key)) cout << key << " does not exist in the hash table. You CANNOT Delete it" << endl; return;
    auto itr = table[hashValue].begin();
    for (;itr != table[hashValue].end(); itr++) {
        if (itr->first == key) {
            table[hashValue].erase(itr);
            cout << key << " Deleted Successfully" << endl;
        }
    }
}
void HashTable::printTable() {
    for (int i = 0; i < hashGroups; i++) {
        cout << i << "| ";
        if (table[i].size() == 0) { 
            cout << endl;
            continue;
        }
        auto itr = table[i].begin();
        for (; itr != table[i].end(); itr++) {
            cout << "(" << itr->first << "," << itr->second << ") ";
        }cout << endl;
    }
}
string HashTable::searchUniversity(string key) {
    int hashValue = hashFunction(key);
    if (isKeyExist(key)) {
        auto itr = table[hashValue].begin();
        for (; itr != table[hashValue].end(); itr++) {
            if (itr->first == key) {
                return itr->second;
            }
        }
    }
    cout << "No Matching Key Exists!" << endl;
    
}
int main()
{
    HashTable HT;
    if (HT.isEmpty()) {
        cout << "Correct Answer, Good job" << endl;
    }
    else {
        cout << "We have a prblem here" << endl;
    }

    HT.insertItem("Jason", "University of Hong Kong");
    HT.insertItem("Jason", "University of Sandiego");
    HT.insertItem("Tom", "University of Korea");
    HT.insertItem("BOB", "Seoul Nationl University"); HT.insertItem("FUCKER", "Dropped Out");
    HT.insertItem("Ally", "Home Schooling");
    HT.insertItem("Johnson", "Indiana University");
    HT.insertItem("SEX", "Sex University");

    HT.insertItem("Belly", "Gyeonggi University");
    HT.insertItem("MotherSucker", "NYU");
    HT.insertItem("Sandy", "BU");
    HT.insertItem("Alex", "CalTECH");
    HT.insertItem("doucheBag", "MIT");
    HT.insertItem("Dum", "Georgia Tech");
   
    
    cout << "\n";

    HT.printTable();
    cout<<"Jason's School is "<<HT.searchUniversity("Jason")<<endl;


    if (HT.isEmpty()) {
        cout << "Ohoh we have a problem" << endl;
    }
    else {
        cout << "Goob job correct answer bro!" << endl;
    }
    return 0;
}
