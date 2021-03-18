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
    vector<long long> v(n);
    for(auto& vi : v) cin >> vi;

    long long sum = accumulate(v.begin(), v.end(), 0ll, [] (auto a, auto b) { return a + b; });
    long long maximum = accumulate(v.begin(), v.end(), 0ll, [] (auto a, auto b) { return max(a,b); });

    if(maximum > sum-maximum) cout << 2 * maximum;
    else cout << sum;
    cout << endl;
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