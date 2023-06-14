#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll base,ll exp,ll mod){
    int res=1;
    while(exp>0){
        if(exp%2==1){
            res= res*base%mod;
        }
        base = base*base%mod;
        exp/=2;
    }
    return res;
}

int main()
{
    int g=2,p=11;//g = primitive number,p=any prime number
    vector<int>v;
    set<int>st;
    for(int i=1;i<p;i++){
        int k = power(g,i,p);
        v.push_back(k);
        st.insert(k);
    }
    if(v.size() == st.size())
        cout<<"Primitive"<<endl;
    else cout<<"Not primitive"<<endl;


}
