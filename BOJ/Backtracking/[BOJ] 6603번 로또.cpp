
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m=6;

vector<int>arr;
vector<int>res;
vector<bool>visited;
vector<bool>visited_level;
int cnt = 0;

void backtracking(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << res[i] << ' ';
		cout << "\n";
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (visited[i])continue;
		if (k != 0) if (arr[i] <= res[k - 1])continue;
		res[k] = arr[i];
		visited[i] = true;
		backtracking(k + 1);
		
		visited[i] = false;
	}
}


int main() {
	
	while (1) {
		cin >> n;
		if (n == 0) return 0;
		res = vector<int>(m);
		visited = vector<bool>(n, 0);
		visited_level = vector<bool>(n, 0);
		arr = vector<int>(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		backtracking(0);
		cout << "\n";
	}



}