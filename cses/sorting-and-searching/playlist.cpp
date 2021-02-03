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
    vector<long long> v(n);
    for(auto& vi : v) cin >> vi;

    int maxLen = 0;
    int currStart = 0;
    map<long long, int> lastSeen;
    for(int i=0; i<n; ++i)
    {
        auto last = lastSeen.find(v[i]);
        if(last == lastSeen.end())
            maxLen = max(maxLen, i - currStart + 1);
        else
        {
            int lastPos = last->second;
            for(int j=currStart; j<=lastPos; ++j)
                lastSeen.erase(v[j]);
            currStart = lastPos+1;
        }
        lastSeen[v[i]] = i;
    }

    cout << maxLen << endl;
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