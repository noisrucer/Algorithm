
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int n, m;
int arr[10];
unordered_set<int>isused;

vector<int>listnum;
void backtracking(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isused.find(listnum[i]) == isused.end()) {
            arr[k] = listnum[i];
            isused.insert(listnum[i]);
            backtracking(k + 1);
            isused.erase(listnum[i]);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        listnum.push_back(num);
    }
    sort(listnum.begin(), listnum.end());
    backtracking(0);
}