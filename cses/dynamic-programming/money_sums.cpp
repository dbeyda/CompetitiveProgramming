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
    int numCoins; cin >> numCoins;
    const int mx = 1000 * numCoins;
    int coins[numCoins];
    for(auto& c : coins) cin >> c;

    vector<vector<bool>> dp(mx+1, vector<bool>(numCoins, false));
    for(int i=0; i<numCoins; ++i) dp[0][i] = true;
    dp[coins[0]][0] = true;

    for(int val = 0; val <= mx; ++val)
        for(int c=1; c<numCoins; ++c)
        {
            dp[val][c] = dp[val][c-1];
            if(val - coins[c] >= 0
               && dp[val-coins[c]][c-1]) dp[val][c] = true;
        }

    int count = 0;
    for(int i=1; i <= mx; ++i)
        if(dp[i][numCoins-1])
            ++count;
    cout << count << endl;

    for(int i=1; i <= mx; ++i)
        if(dp[i][numCoins-1])
            cout << i << " ";
    cout << endl;
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