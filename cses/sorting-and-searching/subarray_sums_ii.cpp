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
    long long target; cin >> target;
    vector<long long> v(n);
    for(auto& vi : v) cin >> vi;

    long long ans = 0;
    long long sum = 0;
    vector<long long> accum(n);
    map<long long, int> m;

    for(int i=0; i<n; ++i)
    {
        sum += v[i];
        accum[i] = sum;
        m[accum[i] - v[i]]++;
        auto it = m.find(accum[i] - target);
        if (it != m.end())
            ans += it->second;

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