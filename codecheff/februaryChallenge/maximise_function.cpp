#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


inline long long calc(long long x, long long y, long long z)
{
    return labs(x-y) + labs(y-z) + labs(z-x); 
}


void solve()
{
    int n; cin >> n;
    vector<long long> v(n);
    for(auto& vi : v) cin >> vi;

    sort(v.begin(), v.end());
    cout << max(calc(v[0], v[1], v.back()), calc(v[0], v[v.size()-2], v.back())) << endl;
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