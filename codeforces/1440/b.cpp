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
    vector<long long> v(n*k);
    for(auto& vi : v) cin >> vi;
    int it = 0;
    int pos = n*k;
    long long sum = 0;
    while(it < k)
    {
        pos -= (n/2 + 1);
        sum += v[pos];
        ++it;
    }
    cout << sum << '\n';
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