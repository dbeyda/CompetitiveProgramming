#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


inline long long nSubarrays(int start, int end)
{
    long long n = end - start + 1;
    return n + (n*(n-1ll))/2ll;
}


void solve()
{
    int n, k;
    cin >> n >> k;

    vector<long long> v(n);
    for(auto& vi : v) cin >> vi;

    map<long long, int> m;
    long long ans = 0;

    int start = 0;
    int end = 0;
    while(true)
    {
        auto it = m.find(v[end]);
        while(end < n && it == m.end())
        {
            m[v[end]] = end;
            ++end;
            it = m.find(v[end]);
        }

        if(it != m.end())
        {
            // end is pointing at a duplicated value
            // move end to element before duplicated value
            --end;
            int dupIndex = it->second;
            ans += nSubarrays(start, end);
            ans -= nSubarrays(dupIndex+1, end);
            start = dupIndex+1;
            end = start;
            m.clear();
        }
        // reached end without duplicates
        else
        {
            ans += nSubarrays(start, end);
            break;
        }
    }
    cout << ans << endl;
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