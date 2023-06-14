#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll base,ll exp,ll mod){
    int res = 1;
    while(exp > 0){
        if(exp%2 == 1){
            res = (res*base)%mod;
        }
        base = (base*base)%mod;
        exp = exp/2;
    }
    return res;
}
int main()
{
    //given r=4,pk=x=3, (g,y,x) = (2,y,3),p=primarynumber=11
    //x=private key
    int r=4,x=3,p=17,g=2;
    int y = power(g,x,p);
    int plaintext = 9;
    //encryption
    int c1 = power(g,r,p);
    int c2 = plaintext*(power(y,r,p));

    //decryption
    cout<<"Plain text : "<<plaintext<<endl;
    cout<<"cipher text :"<<c1<<" "<<c2<<endl;

    int d = power((c2*(power(c1,p-1-x,p))),1,p);
    cout<<"decrypted plaintext :"<<d<<endl;


}
