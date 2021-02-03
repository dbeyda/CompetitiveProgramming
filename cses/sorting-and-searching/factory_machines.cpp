#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


bool trySolution(long long numProducts, long long maxTime, vector<long long>& processingTimes)
{
    for(auto& time : processingTimes)
    {
        numProducts -= maxTime/time;
        if(numProducts <= 0) return true;
    }
    return false;
}


void solve()
{
    int n;
    long long numProducts;
    cin >> n >> numProducts;

    vector<long long> processingTimes(n);
    for(auto& c : processingTimes) cin >> c;
    sort(processingTimes.begin(), processingTimes.end());

    long long start = 0ll;
    // suppose all machines have the slowest machine time
    // upper bound for processing time needed
    long long end =  (numProducts / n + 1) *  processingTimes.back();
    while(start < end)
    {
        long long mid = (start + end) / 2;
        if (trySolution(numProducts, mid, processingTimes)) end = mid;
        else start = mid+1;
    }
    cout << start << endl;
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