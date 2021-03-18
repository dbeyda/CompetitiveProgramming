#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

int dp[1000+1][100000+1];

void solve()
{
    memset(dp, 0, sizeof(int)*(100000+1)*(1000+1));
    int nBooks, budget;
    cin >> nBooks >> budget;
   
    int price[nBooks];
    for(auto& book : price) cin >> book;
    int pages[nBooks];
    for(auto& book : pages) cin >> book;

    int moneyLeft;
    for(int book = 1; book <= nBooks; ++book)
    {
        for(int money = 0; money <= budget; ++money)
        {
            dp[book][money] = dp[book-1][money];
            moneyLeft = money-price[book-1];
            if (moneyLeft >= 0)
                dp[book][money] = max(
                    dp[book-1][moneyLeft] + pages[book-1],
                    dp[book][money]);
        }
    }
    cout << dp[nBooks][budget] << endl;
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