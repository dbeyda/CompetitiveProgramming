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
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    if(a == b)
    {
        cout << x;
        return;
    }
    
    int floors = abs(a-b);
    int baseCost = (floors-1) * min(2*x, y);
    // now we just have to go 1 floor up/down
    int cost = x + y;
    cost = min(cost, (b-a > 0 ? 3*x : x));
    cout << baseCost + cost << endl;
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