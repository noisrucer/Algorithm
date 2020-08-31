
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int>arr;
vector<int>res;
vector<bool>visited;
int cnt = 0;

void backtracking(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << res[i] << ' ';
		cout << '\n';
		return;
	}
	int before = -1;
	for (int i = 0; i < n; i++) {
		if (visited[i])continue;
		if (k != 0)if (arr[i] < res[k - 1])continue;
		if (before == arr[i]) continue;
		before = arr[i];
		res[k] = arr[i];
		visited[i] = true;
		backtracking(k + 1);
		visited[i] = false;
	}
}


int main() {
	cin >> n >> m;
	visited = vector<bool>(n, 0);
	res = vector<int>(m);
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	
	backtracking(0);
	


}