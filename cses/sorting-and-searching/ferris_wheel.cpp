#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


// sort people by weight, so we can do a binary search
// start with biggest weight b, search for maximum value <= x-b
// using binary search. Pair them up, remove a and b from vector
// (how to do the removal efficiently?)

void solve()
{
    int n; cin >> n;
    long long x; cin >> x;
    vector<long long> p(n);
    for(auto& pi : p) cin >> pi;
    sort(p.rbegin(), p.rend());

    int ans = 0;
    int start = 0;
    int end = p.size()-1;
    while(start < end)
    {
        // cout << "Start " << start << " // end " << end << '\n';
        if(p[start] + p[end] > x)
            ++start;
        else
        {
            ++start;
            --end;
        }
        ++ans;
    }
    if(start == end) ++ans;
    cout << ans << '\n';
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