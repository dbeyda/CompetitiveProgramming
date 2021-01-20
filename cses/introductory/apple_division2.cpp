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
    long long sum = 0;
    for(auto& pi : p)
    {
        cin >> pi;
        sum += pi;
    }
    sort(p.rbegin(), p.rend()); // decrescent sorting

    long long sum1 = 0;
    for(auto& pi : p)
        if(sum1 + pi <= sum/2)
            sum1 += pi;
    long long sum2 = sum - sum1;
    cout << abs(sum1 - sum2);
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