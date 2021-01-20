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
    long long n;
    cin >> n;

    long long cost = n+1;
    long long nextLogSize = 1;
    long long myLog = n+1;
    
    // Improvement:
    // this could be done with a binary search
    // on a function that uses the formula of
    // sum(1, n) = n*(1+n)/2, to find in O(log n)
    // the number of logs.
    while (nextLogSize <= myLog)
    {
        myLog -= nextLogSize;
        cost--;
        nextLogSize++;
    }
    cout << cost << endl;
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