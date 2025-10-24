#include <iostream>
using namespace std;

void bubblesort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int bubble[7] = {64, 34, 25, 12, 22, 11, 90};
    bubblesort(bubble, 7);
    
    for(int i = 0; i < 7; i++){
        cout << bubble[i] << " ";
    }
    cout << endl;
    return 0;
}