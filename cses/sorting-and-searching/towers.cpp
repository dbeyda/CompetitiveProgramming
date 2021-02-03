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
    vector<long long> topBoxes;
    long long boxi; 
    for(int i=0; i<n; ++i)
    {
        cin >> boxi;
        int lo = 0;
        int hi = topBoxes.size();
        while(lo < hi)
        {
            int mid = (lo + hi)/2;
            if(boxi < topBoxes[mid]) hi = mid;
            else lo = mid+1;
        }

        if (lo == topBoxes.size()) topBoxes.push_back(boxi);
        else topBoxes[lo] = boxi;
    }
    cout << topBoxes.size() << endl;
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