#include <iostream>
using namespace std;


int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;  
        } else if (target > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; 
}

int main() {
    int arr[10] = {3, 6, 8, 9, 11, 34, 44, 63, 94, 100};
    int n = sizeof(arr) / sizeof(int);
    int t = 8;

    int result = binarySearch(arr, n, t);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
