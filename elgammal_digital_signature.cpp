#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll base, ll exp, ll mod){
    ll res=1;
    while(exp > 0){
        if(exp % 2 == 1){
            res = res*base%mod;
        }
        base = base*base%mod;
        exp/=2;
    }
    return res;
}

int main(){
    int p=6421;//prime number
    int k = 7; //random number
    int x = 3; //private key
    int g = 11; // primitive element

    int m = 1228; // message

    int y = power(g,x,p); //public key
    //find k inverse..
    int k_inverse = 0;
    for(int i=1;i<p-1;i++){
        if((k*i)%(p-1) == 1){
            k_inverse = i;
            break;
        }
    }

    int y1 = power(g,k,p);
    int y2 = ((m-x*y1)*k_inverse)%(p-1);
    if(y2<0)y2 = y2 + (p-1);
    int s = (power(y1,y2,p)*power(y,y1,p))%p;
    int v = power(g,m,p);

    cout<<s<<" "<<v<<endl;

    if(s==v)cout<<"Signature is valid"<<endl;
    else cout<<"Signature is not valid"<<endl;

}

