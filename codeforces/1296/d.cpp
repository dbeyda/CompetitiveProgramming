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
    string s; cin >> s;
    if (n == 1)
    {
        cout << "YES\n0\n";
        return;
    }

    string ans;
    ans.resize(n);
    char lastC1='a';
    char lastC2='a';
    for(int i=0; i<n; ++i)
    {
        if (s[i] >= lastC1)
        {
            lastC1 = s[i];
            ans[i] = '0';
        }
        else if(s[i] >= lastC2)
        {
            lastC2 = s[i];
            ans[i] = '1';
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n" << ans << '\n';
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