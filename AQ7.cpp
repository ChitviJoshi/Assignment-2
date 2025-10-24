#include <iostream>
using namespace std;

int inversion(int A[], int n){
    int inv=0;
    for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
        if(A[i]>A[j]){
            inv+=1;
            cout<<"("<<A[i]<<","<<A[j]<<")";
        }        
    }
    }
    return inv;
}

int main(){   
    int a=9;
    int B[a]={4,7,9,1,0,3,6,8,9};
    int ans=inversion(B,a);
    cout<<endl;
    cout<<"num of inversions"<<ans;
    return 0;
}