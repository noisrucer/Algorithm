// Optimized Bubble Sort.cpp : 


#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		bool flag = false;
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				flag = true; //For each i iteration, if there is at least ONE SWAPPING, then flag will be true so if
							 //flag remains false after the end of each inner loop, it means the array is already sorted
							 //so don't have to continue sorting->time wasting
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (flag == false)
			break;

	}

}
int main()
{
	int size;
	cout << "ENter the size of array: ";
	cin >> size;
	int* arr = new int[size];
	cout << "Enter elements of array " << endl;

	for (int i = 0; i < size; i++) {//array created with the size of 'size'
		cin >> arr[i];
	}
	cout << endl;
	cout << "Unsorted Array: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	bubbleSort(arr, size);

	cout << endl;
	cout << "Sorted Array: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}
