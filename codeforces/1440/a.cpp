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
    int n, c0, c1, h;
    cin >> n >> c0 >> c1 >> h;
    string s;
    cin >> s;
    int cost = 0;

    char cheaper = c0 < c1 ? '0' : '1';
    int cheaperCost = min(c0, c1);
    int otherCost = max(c0, c1);
    int costDiff = abs(c0-c1);

    for(auto& si : s)
    {
        if(si != cheaper && costDiff > h)
            cost += h + cheaperCost;
        else if (si == cheaper)
            cost += cheaperCost;
        else cost += otherCost;
    }
    cout << cost << '\n';
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