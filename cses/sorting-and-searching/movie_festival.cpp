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
    int n; cin >> n;
    vector<pair<long long, long long>> movies(n);
    for(auto& m : movies)  cin >> m.first >> m.second;
    sort(movies.begin(), movies.end(), [](const auto& first, const auto& second)
        {
            return first.second < second.second;
        });
    
    long long ans = 0;
    long long lastFinnishTime = 0;
    for(auto& m : movies)
    {
        if(m.first >= lastFinnishTime)
        {
            ++ans;
            lastFinnishTime = m.second;
        }
    }
    
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