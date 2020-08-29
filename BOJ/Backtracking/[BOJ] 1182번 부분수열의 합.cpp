
#include <iostream>
#include <vector>
using namespace std;
int N, S;
int cnt = 0;
vector<int> arr;

; void func(int cur, int sum) {
	if (cur == N){
		if (sum == S) cnt++;
		return;
	}

	func(cur + 1, sum);
	func(cur + 1, sum + arr[cur]);
}
int main()
{

	cin >> N >> S;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];


	func(0, 0);
	if (S == 0) cnt--;
	cout << cnt;

}

// Run program: Ctrl + F5 