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
    string m, n;
    cin >> m >> n;

    vector<vector<long long>> dp(m.size()+1, vector<long long>(n.size()+1, LONG_LONG_MAX));
    dp[0][0] = 0ll;

    for(int mi=0; mi <= m.size(); ++mi)
    {
        for(int ni=0; ni <= n.size(); ++ni)
        {
            if(ni > 0 && mi > 0)
                dp[mi][ni] = dp[mi-1][ni-1] + (m[mi-1] != n[ni-1]);
            if(ni > 0)
                dp[mi][ni] = min(dp[mi][ni], dp[mi][ni-1]+1);
            if(mi > 0)
                dp[mi][ni] = min(dp[mi][ni], dp[mi-1][ni]+1);
        }
    }
    cout << dp.back().back() << endl;
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