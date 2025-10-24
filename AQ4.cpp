#include <iostream>
#include<cctype>
#include<cstring>
using namespace std;

string concatenate(string a, string b){
    string res=a+b;
    return res;
}

string reverse(string a){
    int n=a.length();
    char temp;
    for(int i=0; i<n/2; i++){
        temp=a[(n-1)-i];
        a[(n-1)-i]=a[i];
        a[i]=temp;
    }
    return a;
}

string delv(string a){
    string vow="aeiouAEIOU";
    int n=a.length();
    string nstr="";
    for(int i=0; i<n; i++){
        if (vow.find(a[i]) != string::npos){
            continue;
        }
        else{
            char c=a[i];
            nstr+=c;
        }
        
    }
    return nstr;
}


string sortString(string a){
    for (int i = 0; i < a.length(); i++) {
        a[i] = tolower(a[i]);
    }
    string a_l=a;
    for(int i=0; i<a_l.length(); i++){
        for(int j=0; j<a_l.length()-i-1; j++){
            char temp;
            if(int(a[j])>int(a[j+1])){
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
        
    }
    return a;
    
}

char Upper_lower(char g){
    int val=int(g);
    int new_val=val+32;
    return char(new_val);
}


int main()
{
    string s1="Namaste";
    string s2="Welcome";
    char ch='B';
    
    string con=concatenate(s1,s2);
    cout<<"concatenated strings "<<con<<endl;
    
    string rev=reverse(s1);
    cout<<"reversed string "<<rev<<endl;
    
    string del=delv(s2);
    cout<<"deleted vowels of string "<<del<<endl;   
    
    string sort=sortString(s1);
    cout<<"sorted string "<<sort<<endl;
    
    char up=Upper_lower(ch);
    cout<<"Upper to lower "<<up<<endl;

    return 0;
}