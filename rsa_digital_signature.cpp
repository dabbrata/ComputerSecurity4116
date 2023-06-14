#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll power(ll base, ll exp, ll mod){
    int res=1;
    while(exp>0){
        if(exp%2==1){
            res = res*base%mod;
        }
        base = base*base%mod;
        exp = exp/2;
    }
    return res;
}

int main()
{
    int p=11,q=17;
    int n=p*q;
    int phi = (p-1)*(q-1);
    int e=2;
    while(e<phi){
        if(__gcd(e,phi) == 1)
            break;
        e++;
    }
    int k=150;
    int d=0;
    for(int i=1;i<k;i++){
        int val = (i*phi+1);
        if(val%e == 0){
            d = int(val/e);

        }
    }
    int msg = 10;

    cout<<"public key :"<<e<<" "<<n<<endl;
    cout<<"private key :"<<d<<" "<<n<<endl;

    //now digital sinature varification
    cout<<"input:"<<msg<<endl;
    int s = power(msg,d,n);
    int v = power(s,e,n);

    cout<<"Sign in : "<<s<<endl<<"Verification : "<<v<<endl;

}
