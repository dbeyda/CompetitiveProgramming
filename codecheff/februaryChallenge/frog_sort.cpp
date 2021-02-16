#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

typedef struct frog
{
public:
    int pos;
    int weight;
    int jump;
} Frog;

void solve()
{
    int n; cin >> n;
    vector<Frog> frogs(n);
    for(int i=0; i<n; ++i) frogs[i].pos = i;
    for(int i=0; i<n; ++i) cin >> frogs[i].weight;
    for(int i=0; i<n; ++i) cin >> frogs[i].jump;

    sort(frogs.begin(), frogs.end(), [] (const Frog& a, const Frog& b) { return a.weight < b.weight; });

    int hits = 0;
    for(int i=1; i<n; ++i)
    {
        int delta =  frogs[i-1].pos - frogs[i].pos + 1;
        while(delta > 0)
        {
            frogs[i].pos += frogs[i].jump;
            delta -= frogs[i].jump;
            ++hits;
        }
    }
    cout << hits << endl;
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