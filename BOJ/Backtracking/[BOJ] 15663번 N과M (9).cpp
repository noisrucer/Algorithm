
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n, m;
vector<int>arr;
vector<bool>visited;
vector<int>res;

void backtracking(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << res[i] << ' ';
		cout << "\n";
		return;
	}
	int before = -1;
	for (int i = 0; i < n; i++) {
		if (visited[i] || before==arr[i]) continue;
			before = arr[i];
			res[k] = arr[i];
			visited[i] = true;
			backtracking(k + 1);
			visited[i] = false;
		
	}

}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		arr.push_back(num);
	}
	res = vector<int>(m);
	visited = vector<bool>(n, 0);
	sort(arr.begin(), arr.end());
	backtracking(0);

}