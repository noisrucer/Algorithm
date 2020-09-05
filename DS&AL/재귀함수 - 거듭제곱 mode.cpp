
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <tuple>
using namespace std;

void recursion(int n) {
	if (n == 0) return;
	recursion(n - 1);
	cout << n << endl;
}

int recursionSum(int n) {
	if (n == 0)return 0;
	return n+recursionSum(n - 1);
	

	
}
using ll = long long;
ll power(ll a, ll b, ll m) {
	if (b == 1) return a % m;
	ll val = power(a, b / 2, m);
	val = val * val % m;
	if (b % 2 == 0)return val;
	return val * a % m;
}
int main()
{
	int a, b, m;
	cin >> a >> b>>m;
	cout<<power(a, b,m);
	
}