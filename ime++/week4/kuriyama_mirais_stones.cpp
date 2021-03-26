#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

void answer(int l, int r, vector<long long>& cumulative)
{
    if(l-1 == 0) cout << cumulative[r-1] << endl;
    else cout << cumulative[r-1] - cumulative[l-2] << endl;
}

void solve()
{
    int n; cin >> n;
    vector<long long> stones(n, 0);
    for(auto& si : stones) cin >> si;
    
    // preprocessing
    vector<long long> cumulative1(n, 0);
    cumulative1[0] = stones[0];
    for(int i=1; i<n; ++i) cumulative1[i] = cumulative1[i-1] + stones[i];
    
    sort(stones.begin(), stones.end());
    vector<long long> cumulative2(n, 0);
    cumulative2[0] = stones[0];
    for(int i=1; i<n; ++i) cumulative2[i] = cumulative2[i-1] + stones[i];

    // queries
    int q; cin >> q;
    int type, l, r;
    for(int i=0; i<q; ++i)
    {
        cin >> type >> l >> r;
        if(type == 1) answer(l, r, cumulative1);
        else answer(l, r, cumulative2);
    }
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