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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto& ai : a) cin >> ai;
    
    int transitions = 0;
    for(int i=0; i<n; ++i)
    {
        if (a[i] > x)
        {
            swap(a[i], x);
            ++transitions;
        }
        else if(i>0 && a[i-1] > a[i])
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << transitions << '\n';
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