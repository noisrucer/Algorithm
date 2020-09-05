
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
vector<int>adj;
vector<int>first_element;
vector<int>visited;

int cycle(int start, int current, int cnt) {
	//start indicates the root element from which the current element started
	//cnt indicates the number of steps taken as of current position
	if (visited[current]) {
		if (first_element[current] != start) return 0;
		
		return cnt - visited[current];
	}

	visited[current] = cnt;
	first_element[current] = start;
	return cycle(start, adj[current], cnt + 1);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int v;
		cin >> v;
		adj = vector<int>(v + 1, 0);
		first_element = vector<int>(v + 1, 0);
		visited = vector<int>(v + 1, 0);
		for (int i = 1; i <= v; i++) cin >> adj[i]; //adjacency list complete

		int res = 0;
		for (int i = 1; i <= v; i++) {
			res+= cycle(i, i, 1);
		}
		cout << v - res<<"\n";
	}
	return 0;

}