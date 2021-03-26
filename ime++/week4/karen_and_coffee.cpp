#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

constexpr int maxSize = 200001;

pair<int, int> recipes[maxSize];
int recomendationsByTemperature[maxSize];
int cumulative[maxSize];

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    for(int i=0; i<n; ++i) cin >> recipes[i].first
                               >> recipes[i].second;

    sort(begin(recipes), begin(recipes)+n);
    
    
    memset(recomendationsByTemperature, 0, maxSize * sizeof(int));
    for(int i=0; i<=maxSize; ++i)
        for(int j=0; j<n; ++j)
        {
            if(i >= recipes[j].first && i <= recipes[j].second)
                ++recomendationsByTemperature[i];
            if(recipes[j].first > i) break;
        }
    cumulative[0] = 0;
    for(int i=1; i<maxSize; ++i)
        cumulative[i] = cumulative[i-1] + (recomendationsByTemperature[i] >= k);

    // queries
    int l, r;
    for(int i=0; i<q; ++i)
    {
        cin >> l >> r;
        cout << cumulative[r] - cumulative[l-1] << endl;
    }
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