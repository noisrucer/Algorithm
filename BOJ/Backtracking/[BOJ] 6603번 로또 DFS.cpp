
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m=6;

vector<int>arr;
vector<int>res;

void backtracking(int start, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << res[i] << ' ';
		cout << "\n";
		return;
	}
	
	for (int i = start; i < n; i++) {
		res[k] = arr[i];
		backtracking(i+1,k + 1);
	}
}


int main() {
	
	while (1) {
		cin >> n;
		if (n == 0) return 0;

		arr = vector<int>(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		backtracking(0,0);
		cout << "\n";
	}



}