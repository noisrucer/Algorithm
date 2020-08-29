// [BOJ] 15650번 N과M (2).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int n, m;
int arr[10];
bool isused[10];

void backtracking(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (isused[i]) continue;
        if (k != 0) if (i < arr[k - 1])continue; //increasing order condition
        arr[k] = i;
        isused[i] = true;
        backtracking(k + 1);
        isused[i] = false;
    }
}
int main()
{
    cin >> n >> m;
    backtracking(0);
}