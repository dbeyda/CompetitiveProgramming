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
    string s1;
    string s2;
    cin >> s1 >> s2;

    long long dp[s1.size()+1][s2.size()+1];
    for(int i=0; i<=s1.size(); ++i) dp[i][0] = i;
    for(int j=0; j <=s2.size(); ++j) dp[0][j] = j;

    for(int i=1; i<=s1.size(); ++i)
        for(int j=1; j <=s2.size(); ++j)
        {
            dp[i][j] = LONG_LONG_MAX;
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
        }
    cout << dp[s1.size()][s2.size()] << endl;
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