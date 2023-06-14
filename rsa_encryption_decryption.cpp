#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll base, ll exp, ll mod)
{
    int res = 1;
    while(exp > 0)
    {
        if(exp%2==1)
        {
            res = res*base%mod;
        }
        base = base*base%mod;
        exp = exp/2;
    }
    return res;
}

int main()
{
    int p=11,q=17;//two prime number given
    //now we have to find the value e and n for p^e mod n and other one
    int n = p*q;
    int phi = (p-1)*(q-1);
    int e=2;
    while(e<phi)
    {
        if(__gcd(e,phi) == 1)
            break;
        e++;
    }
    int k=150;//random integer
    //int d = (k*phi+1)/e;
    int d=0;
    for(int i=1;i<k;i++){
        int val = (i*phi+1);
        if(val%e == 0){
            d = int(val/e);

        }
    }
    cout<<"Public key = ("<<e<<","<<n<<")"<<endl;
    cout<<"Private key = ("<<d<<","<<n<<")"<<endl;

    //now encryp,decrypt
    int msg= 10;
    int enc = power(msg,e,n);
    int dec = power(enc,d,n);

    cout<<"Input message : "<<msg<<endl;
    cout<<"Encrypted message : "<<enc<<endl;
    cout<<"Decypted message : "<<dec<<endl;

}
