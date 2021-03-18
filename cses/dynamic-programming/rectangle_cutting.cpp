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
    int a, b;
    cin >> a >> b;
    int dp[a][b];
    for(int i=0; i<a; ++i)
        for(int j=0; j<b; ++j)
        {
            if(i == j) dp[i][j] = 0;
            else
            {
                int minimum = INT_MAX;
                for(int ii=0; ii<i; ++ii)
                    minimum = min(minimum, dp[ii][j] + dp[i-ii-1][j] + 1);
                for(int jj=0; jj<j; ++jj)
                    minimum = min(minimum, dp[i][jj] + dp[i][j-jj-1] + 1);
                dp[i][j] = minimum;
            }
        }
    cout << dp[a-1][b-1] << endl;
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