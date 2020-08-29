
#include <iostream>
using namespace std;
int n, m;
int arr[10];

void backtracking(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << "\n";
		return;
   }

	for (int i = 1; i <= n; i++) {
		if (k != 0) if (i < arr[k - 1]) continue;
		arr[k] = i;
		backtracking(k + 1);
		
	}
}
int main()
{
	cin >> n >> m;
	backtracking(0);
}