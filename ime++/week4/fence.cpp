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
    int n, k;
    cin >> n >> k;
    vector<int> h(n, 0);
    for(auto& hi : h) cin >> hi;

    long long currSum, minSum;
    int minIdx=0;
    currSum = 0;
    for(int i=0; i<k; ++i) currSum += h[i];
    minSum = currSum;

    for(int i=k; i<n; ++i)
    {
        currSum -= h[i-k];
        currSum += h[i];
        if(currSum < minSum)
        {
            minIdx = i-k+1;
            minSum = currSum;
        }
    }
    cout << minIdx+1 << endl;
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