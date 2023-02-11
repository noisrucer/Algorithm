
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
private:
    int size;
    int capacity;
    vector <int> vect;
    int parent(int i) {
        return i = (i - 1) / 2;
    }
    int left(int i) { 
        return i*2+1; 
    } //i*2;
    int right(int i) {
        return i*2+2; 
    }//i*2+1

public:
    MaxHeap(int n);
    bool isEmpty() const { return size == 0; };
    int getMax() const { return vect[0]; };
    void insertItem(int val);
    void shiftUp(int i);
    int extractMax();
    void shiftDown(int i);
    void showVect();
};
MaxHeap::MaxHeap(int n) {
    size = 0;
    capacity = n;
    vect.resize(capacity);
}
void MaxHeap::shiftUp(int i) {
    if (i == 0)return; //eventually will get to this condition 5/2/2=1 10/2/2/2=1
    if (vect[i] > vect[parent(i)]) {
        swap(vect[parent(i)], vect[i]);
    }
    shiftUp(parent(i)); //recursion
}
void MaxHeap::insertItem(int val) {
    if (size == capacity) {
        cout << "heap is full!" << endl;
        return;
    }
    size++;//size incremented by 1
    int i = size - 1;
    vect[i] = val; 
    shiftUp(i);
    
}

void MaxHeap::shiftDown(int i) {
   //size=4,i=0
    if (i > size) return;
    int swapID = i;

    if (left(i) < size && vect[swapID] < vect[left(i)]) {
        swapID = left(i);
    }
    if (right(i) < size && vect[swapID] < vect[right(i)]) {
        swapID = right(i);
    }
    if (swapID != i) {
        swap(vect[i], vect[swapID]);
        
        cout << endl;
        shiftDown(swapID);
    }
    
}

int MaxHeap::extractMax() {
    if (size == 0) {
        cout << "empty" << endl;
        return -1;
    }
    else if (size == 1) {
        size--;
        return vect[0];
    }
    else {
        int maxNum = vect[0];
        int temp;
         temp = vect[0];
        vect[0] = vect[size - 1];
        vect[size - 1] = temp;
       
        cout << endl;
        size--;
        shiftDown(0);//shiftdown from position 1
        return maxNum;
    }
}

void MaxHeap::showVect() {
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
    cout << endl;
}
int main()
{
    int N = 15;
    MaxHeap PriorityQueue(N); //capacity = 15
    

    PriorityQueue.insertItem(10);
    PriorityQueue.insertItem(20);
    PriorityQueue.insertItem(15);
    PriorityQueue.insertItem(30);
    PriorityQueue.insertItem(40);
    PriorityQueue.showVect();
    
    PriorityQueue.extractMax();
    PriorityQueue.showVect();
   
    PriorityQueue.extractMax();
    PriorityQueue.showVect();

    PriorityQueue.extractMax();
    PriorityQueue.showVect();

    PriorityQueue.extractMax();
    PriorityQueue.showVect();

    PriorityQueue.extractMax();
    PriorityQueue.showVect();
    
   

}
