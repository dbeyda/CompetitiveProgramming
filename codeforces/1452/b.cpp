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
    int nBoxes;
    cin >> nBoxes;
    vector<long long> boxes(nBoxes, 0);
    for(auto& box : boxes) cin >> box;
    
    auto maxIt = max_element(boxes.begin(), boxes.end());
    long long maxEl = *maxIt;
    long long sum = std::accumulate(boxes.begin(), boxes.end(), 0.);

    long long k = max(maxEl, (long long) ceil((double)sum / (nBoxes-1)));
    
    cout << k * (nBoxes-1) - sum << '\n';
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