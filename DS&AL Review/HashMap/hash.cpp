#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

class HashMap{
    private:
        static const int HASH_SIZE = 10;
        list<pair<string,string>>HashTable[HASH_SIZE]; //Collision resolved through chaining using Linked List
    public:
        static int cnt;
        HashMap(){
            cnt++;
        }
        bool isEmpty(); //check if the hashmap is empty 
        bool isKeyExist(string key); //check if the given key exists in the hashmap
        void insertData(string key, string value); //insert data as pair(key,value);
        void deleteData(string key); //delete by key
        string searchByKey(string key); //search value by key
        int hashFunction(string key); //generate hashcode
        void printHash(); //print entire hashmap
};

bool HashMap::isEmpty(){ //iterate through array and check each size
    for(int i=0; i<HASH_SIZE; i++)
        if(HashTable[i].size()!=0) return false;
    return true;
}

int HashMap::hashFunction(string key){ //add up charactes in int and perform modular operation to generate key
    int hash = 0;
    for(char c: key) hash += (int)c;
    return hash % HASH_SIZE;
}

bool HashMap::isKeyExist(string key){
    int hashCode = hashFunction(key); //retrieve respective hashcode 
    list<pair<string,string>>::iterator itr = HashTable[hashCode].begin();
    for(; itr!=HashTable[hashCode].end(); itr++){ //iterate until it matches the key
        if(itr->first == key) return true;
    }
    return false;
}

void HashMap:: insertData(string key, string value){
    if(isKeyExist(key)){ //if the same key is found, return
        cout<<"Key Already Exists!!!\n";
        return;
    }
    int hashCode = hashFunction(key);
    HashTable[hashCode].push_back(make_pair(key,value)); //push back to the end
    cout<<"Inserted Successfully!\n";
}

void HashMap:: deleteData(string key){
    if(!isKeyExist(key)){ //if no key matches, return;
        cout<<"Key Doesn't Exist!!\n";
        return;
    }
    int hashCode = hashFunction(key);
    list<pair<string,string>>::iterator itr = HashTable[hashCode].begin();

    for(; itr!=HashTable[hashCode].end(); itr++){
        if(itr->first == key){ //when key matches, delete
            HashTable[hashCode].erase(itr);
            break;
        }
    }
    cout<<"Deleted Successfully!\n";
}

string HashMap::searchByKey(string key){
    if(!isKeyExist(key)){ //if no key matches, return "error"
        cout<<"Key Doesn't Exist!!\n";
        return "error";
    }

    int hashCode = hashFunction(key);
    auto itr = HashTable[hashCode].begin();
    for(; itr!=HashTable[hashCode].end(); itr++){
        if(itr->first == key) return itr->second; 
    }
    return "";
}

void HashMap::printHash(){
    if(isEmpty()){
        cout<<"Hashmap is empty!!\n";
        return;
    }
    list<pair<string,string>>::iterator itr;
    for(int i=0; i<HASH_SIZE; i++){
        cout<<i<<" | ";
        for(itr=HashTable[i].begin(); itr!=HashTable[i].end(); itr++){
            cout<<"("<<itr->first<<","<<itr->second<<") -> ";
        }cout<<"\n";
    }
}
int HashMap::cnt = 0;

int main(){
    HashMap H1;
    cout<<HashMap::cnt<<"\n";
    H1.printHash();
    H1.insertData("Jason","HKU");
    H1.insertData("Ma","Princeton");
    H1.insertData("Chanjin","Seoul National University");
    H1.insertData("John","HKUST");
    H1.insertData("Smith","Harvard");
    H1.insertData("Mack","MIT");
    H1.printHash();
    H1.deleteData("Smith");
    H1.deleteData("Chang");
    H1.printHash();

    cout<<H1.searchByKey("Ma")<<"\n";
    cout<<H1.searchByKey("Mack")<<"\n";
    cout<<H1.searchByKey("Jason")<<"\n";
    cout<<H1.searchByKey("John")<<"\n";
}