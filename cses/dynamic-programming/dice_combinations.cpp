#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;
long long mod = 1e9 + 7;

using namespace std;


void solve()
{
    int n; cin >> n;
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    
    for(int i=1; i<=n; ++i)
        for(int d=1; d<=6; ++d)
            if(i-d >= 0)
                dp[i] = ((dp[i] % mod) + (dp[i-d] % mod) ) % mod;
    
    cout << dp[n] << endl;
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