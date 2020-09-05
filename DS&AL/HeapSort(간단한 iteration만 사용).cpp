
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void heapify(int heap[], int size) {
	for (int i = 1; i < size; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[c] > heap[root]) {
				swap(heap[root], heap[c]);
			}
			c = root;
		} while (c != 0);
	}
}

void heapSort(int heap[], int size) {
	for (int i = size-1; i >= 0; i--) {
		swap(heap[0], heap[i]);
		int root = 0;
		int c;
		do {
			c = root * 2 + 1;
			if (heap[c] < heap[c + 1] && c < i-1) 
				c++;
			if (heap[c] > heap[root] && c < i) {
				swap(heap[root], heap[c]);
			}
			root = c;
		} while (c<i);
	}
}
int main(){
	int heap[9] = { 7,6,5,8,3,5,9,1,6 };
	int size = sizeof(heap) / sizeof(heap[0]);//size=9;
	heapify(heap, size); //heapify를 먼저 시켜준다.
	for (int x : heap)
		cout << x << " ";
	cout << endl;
	heapSort(heap, size);
	for (int x : heap)
		cout << x << " ";

}
