#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n,m;
    int flag=0;
    cin>>n>>m;
    if(n==0 && m==0){
        cout<<0;
        return 0;
    }

    ++n;

    for(int i=36;i>=0;--i){
        if(pow(n,i)<=m){
            if(flag)cout<<'+';
            flag = 1;


            if((ll)(m/pow(n,i)) != 1 || i==0)
            cout<<(ll)(m/pow(n,i));

            m %= (long long)pow(n,i);

            if(i)cout<<"x";
            if(i>1)cout<<'^'<<i;
        }
        
    }

    return 0;
}