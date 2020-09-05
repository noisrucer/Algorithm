
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int num) {
    int left = 0;
    int right = size - 1;
    bool isthere = 0;
    
    while(left <= right){
        int mid = (left+right) / 2;

        if (arr[mid] == num) 
            return mid;

        else if (arr[mid] < num) 
            left = mid + 1;
            
        else 
            right = mid - 1;      
    } 
    return -1;

   
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

    if (binarySearch(arr, arraySize, num) == -1) {
        cout << "There is no element in the array that matches with the input number " << num << endl;
    }
    else {
        cout << "The matched position is: ";
        cout << binarySearch(arr, arraySize, num);

    }
}