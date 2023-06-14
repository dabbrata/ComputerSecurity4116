#include<bits/stdc++.h>
using namespace std;
int main()
{
    string inp = "Dabbrata das";
    string key = "hellod";
    string res,ans,cipher,decipher;
    for(int i=0;i<inp.size();i++){
        cipher+=inp[i]^key[i%key.size()];
    }
    for(int i=0;i<cipher.size();i++){
        decipher+=cipher[i]^key[i%key.size()];
    }

    cout<<"Input : "<<inp<<endl;
    cout<<"Cipher : "<<cipher<<endl;
    cout<<"Decipher : "<<decipher<<endl;
}
