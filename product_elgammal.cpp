#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll power(ll b, ll p, ll m)
{
    ll j;
    b = b % m;
    if (p == 0)
        return 1;
    else
        j = power(b, p / 2, m);
    j = (j * j) % m;
    if (p % 2 == 1)
        j = (j * b) % m;
    return j;
}

ll exgcd(ll a, ll b, ll *c, ll *d)
{
    if (a == 0)
    {
        *c = 0;
        *d = 1;
        return b;
    }
    ll x, y;
    ll gcd = exgcd(b % a, a, &x, &y);
    *c = y - (b / a) * x;
    *d = x;
    return gcd;
}

int main()
{
    ll i, j;
    ll p = 7477;
    ll alpha = 11;
    ll a = 13; // private key
    ll m1 = 14;
    ll m2 = 5;

    ll beta = power(alpha, a, p);
    cout << "Public Key(P,alpha, beta): " << p << ", " << alpha << ", " << beta << endl;
    ll r1 = 2 + rand() % 10;
    ll c11 = power(alpha, r1, p);
    ll c21 = (m1 * power(beta, r1, p)) % p;
    cout << "Cipher1: " << c11 << ", " << c21 << endl;

    ll r2 = 2 + rand() % 10;
    ll c12 = power(alpha, r2, p);
    ll c22 = (m2 * power(beta, r2, p)) % p;
    cout << "Cipher2: " << c12 << ", " << c22 << endl;

    ll c1 = (c11 * c12) % p;
    ll c2 = (c21 * c22) % p;

    ll mInv1, yy;
    ll tmp = exgcd(power(c11, a, p), p, &mInv1, &yy);
    mInv1 = (p + mInv1) % p;
    ll dec1 = (c21 * mInv1) % p;
    cout << "Decryption1: " << dec1 << endl;

    ll mInv2;
    tmp = exgcd(power(c12, a, p), p, &mInv2, &yy);
    mInv2 = (p + mInv2) % p;
    ll dec2 = (c22 * mInv2) % p;
    cout << "Decryption2: " << dec2 << endl;

    cout << "M: " << dec1 * dec2 << endl;

    ll mInv3;
    tmp = exgcd(power(c1, a, p), p, &mInv3, &yy);
    mInv3 = (p + mInv3) % p;
    ll dec3 = (c2 * mInv3) % p;
    cout << "Decryption3: " << dec3 << endl;

    return 0;
}
