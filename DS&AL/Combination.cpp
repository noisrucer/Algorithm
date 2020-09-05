#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
int N, K;
int arr[6];
int choice[6];
int cnt;
using namespace std;
void comb(int number, int idx) {
	if (idx == K) {
		for (int i = 0; i < K; i++)
			cout << choice[i] << "";
		cout << endl;
		return;
	}

	if (number == N) return;

	choice[idx] = arr[number];
	comb(number + 1, idx + 1);
	comb(number + 1, idx);
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	comb(0, 0);
	return 0;


}