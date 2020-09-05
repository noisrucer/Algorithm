
#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[e];
    int pIndex = s;
    for (int i = s; i < e; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }

    swap(arr[pIndex], arr[e]);
    return pIndex;
}

void quickSort(int arr[], int s, int e) {
    if (s < e) {
        int p = partition(arr, s, e);
        quickSort(arr, s, p - 1);
        quickSort(arr, p + 1, e);
    }
}
int main()
{
    int size;
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << endl;
    cout << "Unsorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr, 0, size-1);
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

}
