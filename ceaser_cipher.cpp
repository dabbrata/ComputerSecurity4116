
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,s2,s3,res;
    cin>>s;
    int n=4;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(ch>='a')s2+=(ch+(n-'a'))%26 + 'a';
        else s2+=(ch+n-'A')%26 + 'A';
    }
    for(int i=0;i<s2.size();i++){
        char ch=s2[i];
        if(ch>='a')s3+=(ch -(n+'a')+26)%26 + 'a';
        else s3+=(ch-(n+'A')+26)%26 + 'A';
    }
    cout<<"Encrypted: "<<s2<<endl<<"Decrypted :"<<s3<<endl;
}
