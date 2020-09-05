
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int func2(int arr[], int N) {
	int table[101] = {};
	for (int i = 0; i < N; i++) {
		if (table[100 - arr[i]] == 1) return 1;
		else table[arr[i]] = 1;
	}
	return 0;

}
int main()
{
	int arr[] = { 1,23,53,77,60 };
	int N = 5;
	cout<<func2(arr, N);

}
