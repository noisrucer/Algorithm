
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
int n, m;
vector<int>arr;
vector<int>res;
unordered_set<int>visited;

void backtracking(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << res[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited.count(arr[i])) continue;
		if (k != 0 && arr[i] <= res[k - 1])continue;
		res[k] = arr[i];
		visited.insert(arr[i]);
		backtracking(k + 1);
		visited.erase(arr[i]);
	}

}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	res = vector<int>(m);
	sort(arr.begin(), arr.end());

	backtracking(0);
}