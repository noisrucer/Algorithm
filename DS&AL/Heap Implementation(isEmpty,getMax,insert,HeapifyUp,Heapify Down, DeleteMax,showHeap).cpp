// Heap Implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    int size{};
    vector <int> vect = { -1 };
    int parent(int i) { return i >> 1; };//i/2;
    int left(int i) { return i << 1; }; //i*2;
    int right(int i) { return (i << 1) + 1; };//i*2+1

public:
    bool isEmpty() const { return size == 0; };
    int getMax() const { return vect[1]; };
    void insertItem(int val);
    void shiftUp(int i);
    int extractMax();
    void shiftDown(int i);
    void showVect();
};
void MaxHeap::shiftUp(int i) {
    if (i > size) return;
    if (i == 1)return; //eventually will get to this condition 5/2/2=1 10/2/2/2=1
    if (vect[i] > vect[parent(i)]) {
        swap(vect[parent(i)], vect[i]);
    }
    shiftUp(parent(i)); //recursion
}
void MaxHeap::insertItem(int val) {
    if (size + 1 >= vect.size()) {//size=0, vect = 1 ->size=1, vect=2
        vect.push_back(0);
    }
    vect[++size] = val;
    shiftUp(size);
    return;
}

void MaxHeap::shiftDown(int i) {
    if (i > size) return;
    int swapID = i;

    if (left(i) <= size && vect[i] < vect[left(i)]) {
        swapID = left(i);
    }
    if (right(i) <= size && vect[swapID] < vect[right(i)]) {
        swapID = right(i);
    }
    if (swapID != i) {
        swap(vect[i], vect[swapID]);
        shiftDown(swapID);
    }
    return;
}

int MaxHeap:: extractMax() {
    int maxNum = vect[1];
    swap(vect[1], vect[size--]); //first element <-> last element
    shiftDown(1);//shiftdown from position 1
    return maxNum;
}

void MaxHeap:: showVect() {
    for (int i = 1; i <= size; i++) {
        cout << vect[i] << " ";
    }
    cout << endl;
}
int main()
{
    MaxHeap PriorityQueue;
    if (PriorityQueue.isEmpty()) {
        cout << "Yes this is empty" << endl;
    }
    else {
        cout << "We have a problem with our isEmpty Function" << endl;
    }

    PriorityQueue.insertItem(10);
    PriorityQueue.insertItem(20);
    PriorityQueue.insertItem(15);
    PriorityQueue.insertItem(30);
    PriorityQueue.insertItem(40);
    PriorityQueue.showVect();
    cout << PriorityQueue.getMax() << endl;
    PriorityQueue.extractMax();
    PriorityQueue.showVect();
    cout << PriorityQueue.getMax() << endl;
    PriorityQueue.extractMax();
    PriorityQueue.showVect();
    cout << PriorityQueue.getMax() << endl;
   
}
