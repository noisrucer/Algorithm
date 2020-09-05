
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//0 1 2 3 4 5 6 7 8 9
//4 2 2 7 8 1 2 8 1 0
int maxSumArray(vector<int>arr, int k) {
	int minWindowSize = INT_MAX;
	int windowStart = 0;
	int currentSum = 0;
	for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
		currentSum += arr[windowEnd];
		while(currentSum > k) {
			currentSum -= arr[windowStart++];
		}
		if (currentSum == k) {
			cout << "[" << windowStart << "," << windowEnd << "]" << endl;
			minWindowSize = min(minWindowSize, windowEnd - windowStart + 1);
			currentSum -= arr[windowStart++];
		}
	}
	return minWindowSize;
}
int main()
{
	int k = 8; 
	vector<int>arr = { 4,2,2,7,8,1,2,8,1,0 };
	cout << maxSumArray(arr, k);
}