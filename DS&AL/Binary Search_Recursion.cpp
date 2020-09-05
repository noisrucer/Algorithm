
#include <iostream>
using namespace std;

int binarySearch(int arr[],int l, int r, int key) {
    int m = (l + r) / 2; 
    if (l == r) {
        if (arr[l] == key)
            return l;
        else
            return 0;
    }
    else {
        if (key == arr[m])
            return m;
        else if (key < arr[m])
        binarySearch(arr, l, m - 1, key);
        else
        binarySearch(arr, m + 1, r, key);
    }
    
}
int main()
{
    int* arr;
    int arraySize;
    cout << "Enter size of array: ";
    cin >> arraySize; // Type 8.

    arr = new int[arraySize];

    for (int i = 0; i < arraySize; i++) {
        cin >> arr[i];
    }
    cout << endl;
    cout << "Find number you want to search in the array: ";
    int num;
    cin >> num;
    int l = 0;
    int r = arraySize - 1;

    if (binarySearch(arr, l,r, num) == false) {
        cout << "There is no element in the array that matches with the input number " << num << endl;
    }
    else {
        cout << "The matched position is: ";
        cout << binarySearch(arr, l, r, num);
    }

    
}