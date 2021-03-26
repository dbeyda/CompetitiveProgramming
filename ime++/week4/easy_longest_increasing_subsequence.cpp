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
    int nums[n];
    for(auto& ni : nums) cin >> ni;

    vector<int> longest(n, 0);
    for(int end=0; end<n; ++end)
    {
        longest[end] = 1;
        for(int i=0; i<end; ++i)
        {
            if(nums[i] < nums[end])
                longest[end] = max(longest[end], longest[i]+1);
        }
    }
    int m = accumulate(begin(longest), end(longest), 0,
                [] (int a, int b) {return max(a, b);});
    cout << m << endl;
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