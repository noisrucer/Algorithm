// [BOJ] 9663번 N-Queen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
int N,S;
int cnt = 0;
vector<int> arr;
vector<bool> isused;
;void func(int k, int sum) {
	if (k == N) return;

	for (int i = 0; i < N; i++) {
		if (isused[arr[i]])continue;
		sum += arr[i];
		isused[arr[i]] = true;
		if (sum == S) cnt++;
		func(k + 1, sum);
		isused[arr[i]] = false;



	}
}
int main()
{

	cin >> N >> S;
	arr.resize(N);
	isused.resize(N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	
	func(0,0);
	cout << cnt;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
