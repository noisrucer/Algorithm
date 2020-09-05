
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int l(int p) { return p * 2 + 1; }
int r(int p) { return p * 2 + 2; }
void heapify(vector<int>& heap, int size, int i) {
	//i is current node to be heapified
	// left = l(i), right = r(i);
	int swapID = i;
	if (l(i) < size && heap[l(i)] > heap[swapID]) swapID = l(i);
	if (r(i) < size && heap[r(i)] > heap[swapID]) swapID = r(i);
	
	if (swapID != i) {
		swap(heap[i], heap[swapID]);
		heapify(heap, size, swapID);
	}
}
void heapsort(vector<int>& heap, int size) {

	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(heap, size, i);
	}
	//heapify COMPLETE
	//sorting->deleteMax procedure
	for (int i = size - 1; i > 0; i--) {
		swap(heap[0], heap[i]);
		size--;
		heapify(heap, size, 0);
	}
}
void printheap(vector<int> heap) {
	for (int x : heap)
		cout << x << " ";
}
int main() {
	int N;
	cin >> N;
	vector<int> heap;
	
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		heap.push_back(num);
	}
	//heap={4,6,2,10,2} N=5;
	heapsort(heap, N);
	printheap(heap);



}