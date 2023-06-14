#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 100000007

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
int main(){

    int p=7477,g=11;
    int r1=rand()%10,r2=rand()%10;
    int m1=14,m2=5;
    int x = 13;//private key

    int y = power(g,x,p);

    int c11 = power(g,r1,p);
    int c12 = power(g,r2,p);

    int c21 = (power(m1,1,p)*power(y,r1,p))%p;
    int c22 = (power(m2,1,p)*power(y,r2,p))%p;

    int c1 = (c11*c12)%p;
    int c2 = (c21*c22)%p;

    cout<<c1<<" "<<c2<<" "<<endl;

    int left = (c2*power(c1,p-1-x,p))%p;
    int right = (m1*m2);

    cout<<left<<" "<<right<<endl;
}
