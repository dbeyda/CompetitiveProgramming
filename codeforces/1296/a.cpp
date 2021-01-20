#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


void solve()
{
    int n; cin >> n;
    int vi;
    bool hasEven = false;
    bool hasOdd = false;

    for(int i=0; i<n; ++i)
    {
        cin >> vi;
        if (!hasEven && vi % 2 == 0) hasEven = true;
        if (!hasOdd && vi % 2) hasOdd = true;
    }
    if(n % 2 && hasOdd) cout << "YES\n";
    else if (hasOdd && hasEven) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w+", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long t=1;
    cin >> t;
    for(int it=1; it<=t; it++)
        solve();
    return 0;
}