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
    constexpr int mod = 1e9 + 7;
    int size, m;
    cin >> size >> m;

    int vec[size];
    for(auto& vi : vec) cin >> vi;

    int dp[size+1][m+1];
    memset(dp, 0, sizeof(int) * (size+1) * (m+1));

    // first stop
    if(vec[0]) dp[1][vec[0]] = 1;
    else for(int i=1; i<=m; ++i) dp[1][i] = 1;

    for(int sz = 2; sz <= size; ++sz)
    {
        if(vec[sz-1])
        {
            for(int i = vec[sz-1]-1; i <= vec[sz-1]+1; ++i)
                if(i <= m)
                    dp[sz][vec[sz-1]] = (dp[sz][vec[sz-1]] + dp[sz-1][i]) % mod;
        }
        else
            for(int mi = 1; mi <= m; ++mi)
            {
                for(int i = mi-1; i <= mi+1; ++i)
                    if(i <= m)
                        dp[sz][mi] = (dp[sz][mi] + dp[sz-1][i]) % mod;
            }
    }
    
    // for(auto& line : dp)
    // {
    //     for(auto& val : line)
    //         cout << val << " ";
    //     cout << endl;
    // }
    
    int ans = 0;
    for(auto& x : dp[size]) ans = (ans + x) % mod;
    cout << ans << endl;
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