#include <iostream>
using namespace std;

int un_ele(int a[], int n){
    int ans=0;
    for(int i=0; i<n; i++){
        int c=0;
        for(int j=0; j<n;j++){
            if(i==j){
                continue;
            }
            if(a[i]==a[j]){
                break;
            }
            else{
                c+=1;
            }
        }
        if(c==n-1){
            ans+=1;
        }
        
    }
    return ans;
}
    

int main()
{
    int A[6]={5,3,6,3,7,5};
    int ins=un_ele(A,6);
    cout<<"no of unique elements"<<ins;

    return 0;
}