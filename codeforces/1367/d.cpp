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
    string s; cin >> s;
    int m; cin >> m;
    vector<int> b(m, 0);
    for(auto& bi : b) cin >> bi;

    vector<pair<int*, int>> bRef(m);
    for(int i=0; i<m; ++i) bRef[i] = make_pair(&b[i], i);

    sort(bRef.begin(), bRef.end(),
        [](const pair<int*, int>& a, const pair<int*, int>& b) -> bool
        {
            return *(a.first) < *(b.first); 
        });
    sort(s.rbegin(), s.rend());

    string ans;
    ans.resize(m);
    for(int i=0; i<m; ++i)
    {
        int pos = bRef[i].second;
        ans[pos] = s[i];
    }
    cout << ans << '\n';
    // for(auto &bi : bRef) cout << *(bi.first) << " ";

    // for(auto &bi : bRef) cout << *(bi.first) << " ";
    // cout << '\n';
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