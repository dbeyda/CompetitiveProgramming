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
    long long x; cin >> x;
    vector<long long> v(n);
    map<long long, int> m;
    for(int i=0; i<n; ++i)
    {
        cin >> v[i];
        auto it = m.find(v[i]);
        if (it != m.end())
        {
            cout << it->second+1 << " " << i+1 << endl;
            return;
        }
        else m[x-v[i]] = i;
    }
    cout << "IMPOSSIBLE\n";
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