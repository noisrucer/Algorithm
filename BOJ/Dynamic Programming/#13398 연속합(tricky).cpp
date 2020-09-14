
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;
int dp_left[100001];
int dp_right[100001];
int arr[100001];
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	if (n == 1) {
		cout << arr[0];
		return 0;
	}

	int mx = INT_MIN;
	dp_left[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp_left[i] = max(arr[i] + dp_left[i - 1], arr[i]);
	}
	mx = *max_element(dp_left, dp_left + n);

	dp_right[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		dp_right[i] = max(arr[i] + dp_right[i + 1], arr[i]);
	}
	mx = *max_element(dp_right, dp_right + n);

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			mx = max(mx, dp_right[1]);
			continue;
		}
		if (i == n - 1) {
			mx = max(mx, dp_left[n - 2]);
			continue;
		}
		mx = max(mx,dp_left[i - 1] + dp_right[i + 1]);
	}
	cout << mx;
	
	
}