// Bubble Sort Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}

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
