
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;
vector<int>vec;
int sum(int n) {
	int mx = INT_MIN;
	int current_mx = 0;
	for (int i = 0; i < vec.size(); i++) {
		current_mx += vec[i];
		if (current_mx < vec[i]) {
			current_mx = vec[i];
		}
		mx = max(current_mx, mx);
	}
	return mx;
}
int main()
{
	int n;
	cin >> n;
	vec = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	cout << sum(n);

}
