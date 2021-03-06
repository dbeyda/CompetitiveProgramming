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
    vector<long long> p(n);
    for(auto& pi : p) cin >> pi;
    long long sum = accumulate(p.begin(), p.end(), 0ll, [](long long a, long long b) {return a + b;});
    long long best = sum;

    for(int i=0; i < (1 << n); ++i)
    {
        long long current = 0;
        for(int j=0; j<n; ++j)
            if(i & (1 << j)) current += p[j];
        best = min(best, abs(sum-2*current));
    }
    cout << best;
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