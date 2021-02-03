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
    long long n; cin >> n;
    vector<int> dp(n+1, -1);

    dp[n] = 0;
    for(int i=n; i>=0; --i)
    {
        int j = i;
        do {
            int digit = j % 10;
            if(dp[i] >= 0)
            {
                if(dp[i-digit] >= 0) dp[i-digit] = min(dp[i-digit], dp[i]+1);
                else dp[i-digit] = dp[i]+1;
            }
        } while ( j /= 10);
    }
    cout << dp[0] << endl;
    // for(auto& vi : dp) cout << vi << " ";
    // cout << endl;
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