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
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(auto& c : coins) cin >> c;

    vector<long long> dp(x+1, -1);
    dp[0] = 0ll;

    for(int i=1; i<=x; ++i)
    {
        for(auto& c : coins)
        {
            if(i-c >= 0 && dp[i-c] >= 0)
            {
                if(dp[i] == -1) dp[i] = dp[i-c]+1;
                else dp[i] = min(dp[i], dp[i-c]+1);
            }
        }
    }
    cout << dp[x] << endl;
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