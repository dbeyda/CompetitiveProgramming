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
    int n; long long x;
    cin >> n >> x;

    vector<long long> v(n);
    for(auto& vi : v) cin >> vi;

    map<long long, int> m;
    for(int i=0; i<v.size(); ++i) m[x-v[i]] = i;

    for(int i=0; i<v.size()-1; ++i)
        for(int j=i+1; j<v.size(); ++j)
            if(m.count(v[i]+v[j]) && m[v[i]+v[j]] != i && m[v[i]+v[j]] != j)
            {
                cout << i+1 << ' ' << j+1 << ' ' << m[v[i]+v[j]]+1 << endl;
                return;
            }
    cout << "IMPOSSIBLE" << endl;

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