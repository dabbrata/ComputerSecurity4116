#include<bits/stdc++.h>
using namespace std;
int main()
{
    int row,col;
    string s = "Hello Dabbrata Das";
    string k = "das";
    col = k.size();
    row = (s.size() + col - 1)/col;

    int ix=0;
    int arr[row][col];
    for(int j=0;j<col;j++){
        for(int i=0;i<row;i++){
            arr[i][j] = s[ix++];
        }
    }

    string cipher;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cipher += arr[i][j];
        }
    }
    string decipher;
    for(int j=0;j<col;j++){
        for(int i=0;i<row;i++){
            decipher += arr[i][j];
        }
    }
    cout<<"Input : "<<s<<endl;
    cout<<"Cipher : "<<cipher<<endl;
    cout<<"Decipher : "<<decipher<<endl;
}
