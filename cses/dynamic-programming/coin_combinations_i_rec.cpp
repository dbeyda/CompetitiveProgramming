#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

long long mod = 1e9 + 7;

using namespace std;


long long ways(int x, vector<int>& coins, vector<long long>& cache)
{
    if(x < 0) return 0;
    if(cache[x] >= 0) return cache[x];
    
    long long ans = 0;
    for(auto& c : coins)
        ans = (ans + ways(x-c, coins, cache)) % mod;
    cache[x] = ans;
    return ans;
}


void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(auto& c : coins) cin >> c;
    sort(coins.rbegin(), coins.rend());
    vector<long long> cache(x+1, -1);
    cache[0] = 1ll;

    cout << ways(x, coins, cache) << endl;
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