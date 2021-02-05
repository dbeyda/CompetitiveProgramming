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
    int n, k;
    cin >> n >> k;
    multiset<long long, greater<long long>> s;
    for(int i=0; i<k; ++i) s.insert(0ll);
    
    vector<pair<long long, long long>> movies(n);
    for(auto& m : movies) cin >> m.first >> m.second;

    sort(movies.begin(), movies.end(), [] (const auto& a, const auto& b) { return a.second < b.second; });

    long long startTime, endTime;
    long long total = 0;
    for(int i=0; i<n; ++i)
    {
        startTime = movies[i].first;
        endTime = movies[i].second;
        // cout << "------------\n";
        // cout << "movie " << startTime << " " << endTime << endl;
        // cout << "multiset ";
        // for(auto& si : s) cout << si << " ";
        // cout << endl;
        auto it = s.lower_bound(startTime);
        if(it != s.end())
        {
            ++total;
            s.erase(it);
            s.insert(endTime);
        }
    }
    cout << total << endl;
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