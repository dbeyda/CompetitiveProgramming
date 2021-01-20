#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

double eps = 1e-12;
long long mod = 998244353;

template <typename T>
T pow_mod(T a, T b, T mod) {
    T res = 1;
    while(b) {
        if(b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2ll;
    }
    return res;
}

template <typename T>
T inv_mod(T a, T mod) { return pow_mod<T>(a, mod - 2, mod) % mod; }



void solve()
{
    long long n; cin >> n;
    long long m;
    if (n <= 2)
        m = 1;
    else
    {
        long long a, b, c, aux;
        a = b = 1;
        c = a + b;
        for(int i=3; i<=n; ++i)
        {
            c = ((a % mod) + (b % mod)) % mod;
            a = b;
            b = c;
        }
        m = c;
    }
    cout << ((m % mod) * inv_mod(pow_mod((long long) 2, n, mod), mod)) % mod << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w+", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long t=1;
    // cin >> t;
    for(int it=1; it<=t; it++)
        solve();
    return 0;
}