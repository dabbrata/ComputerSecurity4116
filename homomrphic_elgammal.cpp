#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll base, ll exp ,ll mod)
{
    int res = 1;
    while(exp>0){
        if(exp%2 == 1)
        {
            res = res*base%mod;
        }
        base = base*base%mod;
        exp/=2;
    }
    return res;
}
int main()
{
    int m1=14,m2=5,g=11,p=7477,r1=5,r2=6;
    int x=13;
    int y  = power(g,x,p);
    int c11 = power(g,r1,p);
    int c12 = power(g,r2,p);
    int c21 = power((power(m1,1,p)*power(y,r1,p)),1,p);
    int c22 = power((power(m2,1,p)*power(y,r2,p)),1,p);

    int c1 = (c11*c12)%p;
    int c2 = (c21*c22)%p;

    int M = m1*m2;
    int d = power((c2*power(c1,p-1-x,p)),1,p);

    cout<<M<<" "<<d<<endl;
}
