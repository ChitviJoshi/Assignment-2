#include <iostream>
using namespace std;

int cal_cum(int arr[], int n){
    int actual_sum=(arr[n-1]*(arr[n-1]+1))/2;
    int c_sum=0;
    for(int i=0; i<n; i++){
        c_sum+=arr[i];
    }
    int diff= actual_sum-c_sum;
    if(diff==0){
        return -1;
    }
    else{
        return diff;
    }
}

int main()
{   
    int a=7;
    int A[a]={1,2,3,4,5,6,8};
    int missing=cal_cum(A,a);
    if(missing==-1){
        cout<<"none missing";
    }
    else{
        cout<<"missing num is "<<missing;
    }
    return 0;

}