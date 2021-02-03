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
    long long x;
    int n;
    cin >> x >> n;
    vector<long long> v(n);
    for(auto& vi : v) cin >> vi;

    map<long long, long long, greater<long long>> m; // map: start -> size
    m[0] = x;
    multiset<long long> s;
    s.insert(x);
    for(auto& vi : v)
    {
        auto it = m.lower_bound(vi);
        // cout << "lower_bound[" << vi << "] = " << it->first << endl;
        long long originalSize = it->second;
        // cout << "erasing " << it->second << " // ";
        s.erase(s.find(it->second));
        it->second = vi - it->first;
        // cout << "adding " << it->second << " and ";
        s.insert(it->second);
        m[vi] = originalSize - (vi - it->first);
        // cout << m[vi] << endl;
        s.insert(m[vi]);
        long long max_size = *(s.rbegin());
        cout << max_size << " ";
    }

    cout << endl;

    // for(auto& p : m)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }
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