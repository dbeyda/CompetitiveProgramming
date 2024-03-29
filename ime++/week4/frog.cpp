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
    int h[n];
    for(auto& hi : h) cin >> hi;

    if(n == 1)
    {
        cout << 0 << endl;
        return;
    }
    
    int dp[n];
    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);
    for(int i=2; i<n; ++i)
    {
        dp[i] = dp[i-1] + abs(h[i]-h[i-1]);
        dp[i] = min(dp[i], dp[i-2] + abs(h[i]-h[i-2]));
    }
    cout << dp[n-1] << endl;
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