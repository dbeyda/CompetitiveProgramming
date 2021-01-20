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
    long long row, col;
    cin >> row >> col;
    long long m = max(row, col);
    char idx = m == row ? 'r' : 'c';
    
    long long start = idx == 'r' ? (row - (row % 2)) * (row - (row % 2)) + (row % 2)
                                    : (col - (1-(col % 2))) * (col - (1-(col % 2))) + 1 - (col % 2);
    // cout << start << '\n';
    long long ans = idx == 'r' ? (row % 2 ? start + (col-1) : start - (col-1))
                                 : col % 2 ? start - (row-1) : start + (row-1);
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
    cin >> t;
    for(int it=1; it<=t; it++)
        solve();
    return 0;
}