#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
int n, m;
int arr[9];

void backtracking(int k) {
	

}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr+n);
	int per[5] = { 0,0,1,1,1 };
	do {
		for (int i = 0; i < n; i++) {
			if (per[i] == 1)continue;
			cout << arr[i]<<" ";
		}
		cout << "\n";
	} while (next_permutation(per, per + n));
//	backtracking(0);
}