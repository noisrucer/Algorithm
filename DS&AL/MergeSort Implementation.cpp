
#include <iostream>

using namespace std;
void merge(int arr[], int l, int r, int m) {
	int i, j, k;
	int* temp = new int[r - l + 1];
	i=l,k=0;
	j = m + 1;
	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			k++;
			i++;
		}
		else {
			temp[k] = arr[j];
			k++;
			j++;
		}
	}

	while (i <= m) {
		temp[k++] = arr[i++];
		
	}

	while (j <= r) {
		temp[k++] = arr[j++];
		
	}

	for (i = l; i <= r; i++) {
		arr[i] = temp[i - l];
	}

}
void mergesort(int arr[], int l, int r) {
	
	if (l < r) {
		int m = (l + r) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);
		merge(arr, l, r, m);
	}
}
int main()
{
	int arr[10] = { 9,3,7,5,6,4,8,2,4,34554 };
	int n = 10;
	mergesort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << "->" << arr[i];

}
