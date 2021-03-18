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
    int mod = 1e9 + 7;

    int n; cin >> n;
    char board[n][n];
    for(auto& line : board)
        for(auto& cell : line)
            cin >> cell;
    
    // for(auto& line : board)
    // {
    //     for(auto& cell : line)
    //         cout << cell;
    //     cout << endl;
    // }

    
    int dp[n][n];
    for(int row = 0; row<n; ++row)
    {
        for(int col=0; col<n; ++col)
        {
            if(board[row][col] == '*')
                dp[row][col] = 0;
            else if(col == 0 && row == 0) dp[0][0] = 1;
            else
            {
                dp[row][col] = (row > 0 ? dp[row-1][col] : 0 ) + (col > 0 ? dp[row][col-1] : 0);
                dp[row][col] %= mod;
            }
        }
    }
    cout << dp[n-1][n-1] << endl;

    // cout << endl;
    // for(auto& line : dp)
    // {
    //     for(auto& cell : line)
    //         cout << cell << " ";
    //     cout << endl;
    // }
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