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
    vector<long long> l(n);
    for(auto& li : l) cin >> li;
    
    sort(l.begin(), l.end());
    long long target;
    if (l.size() % 2) target = l[l.size()/2];
    else
        target = (l[l.size()/2] + l[l.size()/2 - 1] ) / 2;
    
    long long cost = accumulate(l.begin(), l.end(), 0ll, 
        [target] (long long a, long long b) -> long long { return a + abs(b-target); });
    cout << cost << endl;
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