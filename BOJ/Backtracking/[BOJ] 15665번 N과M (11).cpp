
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int>arr;
vector<int>res;

void backtracking(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << res[i] << ' ';
		cout << '\n';
		return;
	}
	int before = -1;
	for (int i = 0; i < n; i++) {
		if (before == arr[i]) continue;
		before = arr[i];
		res[k] = arr[i];
		backtracking(k + 1);
	}
}


int main() {
	cin >> n >> m;
	res = vector<int>(m);
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	
	backtracking(0);
	


}