#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


void solve(int n)
{
    vector<long long> bets(n);
    for(auto& bi : bets) cin >> bi;

    vector<long long> dp(n);
    dp[0] = bets[0];
    for(int i=1; i<n; ++i)
        dp[i] = max(dp[i-1]+bets[i], bets[i]);
    
    long long ans = accumulate(begin(dp), end(dp), dp[0],
        [] (long long a, long long b) { return max(a, b); });
    
    if (ans > 0) cout << "The maximum winning streak is "
                      << ans << "." << endl;
    else cout << "Losing streak." << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w+", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    do
    {
        solve(n);
        cin >> n;
    } while(n != 0);
    return 0;
}