#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


bool trySolution(long long maxSum, int groupsLeft, vector<long long>& v)
{
    int n = (int) v.size();
    long long currSum = 0;
    int i = 0;
    while(i < n && groupsLeft)
    {
        if(currSum + v[i] <= maxSum)
        {
            currSum += v[i];
            ++i;
        }
        else
        {
            // cout << "Minus one group..." << endl;
            --groupsLeft;
            currSum = 0;
        }
    }
    // cout << "--------------" << endl;
    // cout << "groupsLeft " << groupsLeft << endl;
    // cout << "currSum " << currSum << endl;
    // cout << "maxSum " << maxSum << endl;
    return groupsLeft > 0;
}


void solve()
{
    int n, nGroups;
    cin >> n >> nGroups;

    vector<long long> v(n);
    for(auto& vi : v) cin >> vi;

    long long start = 1ll;
    long long end = accumulate(v.begin(), v.end(), 0ll, [] (auto a, auto b) { return a + b; });
    // cout << "end " << end << endl;
    while(start < end)
    {
        long long mid = (start + end) / 2;
        if (trySolution(mid, nGroups, v)) end = mid;
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