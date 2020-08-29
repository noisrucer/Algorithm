//next_permutation STL Algorithm
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int arr[] = { 1,2,3,4 };
	do {
		for (int i = 0; i < 4; i++) {
			cout << arr[i];
		}
		cout << "\n";
	} while (next_permutation(arr+2, arr + 4));

	cout << "\n\n";
	int arr1[] = { 0,0,0,0,0,1,1 };
	do {
		for (int i = 3; i <= 6; i++) {
			if (arr1[i]==0) 
			cout << i;
		}
		cout << "\n";
	} while (next_permutation(arr1+3, arr1 + 7));
	

}

// Run program: Ctrl + F5 