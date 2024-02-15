#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a,b;
    cin>>a>>b;
    if(a < b){
        if(b<2*a)cout<<0<<' '<<2*(b-a);
        else if(b == 2*a)cout<<a<<' '<<a;
        else if(b <= 3*a)cout<<(b-2*a)<<' '<<b;
        else cout<<a<<' '<<3*a;
    }
    else if(a == b)cout<<a<<' '<<a;
    else{
        if(a<2*b)cout<<2*(a-b)<<' '<<0;
        else if(a == 2*b)cout<<b<<' '<<b;
        else if(a <= 3*b)cout<<a<<' '<<(a-2*b);
        else cout<<3*b<<' '<<b;
    }
    return 0;
}