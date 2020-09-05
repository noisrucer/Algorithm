
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxSumArray(vector<int>arr, int k) {
	int maxSum = INT_MIN;
	int currentSum = 0;
	for (int i = 0; i < arr.size(); i++) {
		currentSum += arr[i];
		if (i >= k - 1) {
			maxSum = max(maxSum, currentSum);
			currentSum -= arr[i - (k - 1)];
		}
	}
	return maxSum;
}
int main()
{
	int k = 3; 
	vector<int>arr = { 4,2,2,7,8,1,2,8,1,0 };
	cout << maxSumArray(arr, k);
}