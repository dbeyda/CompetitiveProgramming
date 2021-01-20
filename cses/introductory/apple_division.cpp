#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


void generate(int start, vector<long long> &p,
              unsigned int &groups, long long &s1, 
              long long &s2, long long &lowest)
{
    lowest = min(lowest, abs(s1-s2));
    if(s1 >= s2) return;
    unsigned int bitmask;
    for(int i=start; i<p.size(); ++i)
    {
        bitmask = 1 << (31-i);
        if((groups & bitmask) == 0)
        {
            generate(start+1, p, groups, s1, s2, lowest);
            groups = groups | bitmask;
            s2 -= p[i];
            s1 += p[i];
            generate(start+1, p, groups, s1, s2, lowest);
            s2 += p[i];
            s1 -= p[i];
            groups = groups & (~bitmask);
        }
    }
}


void solve()
{
    long long s1 = 0;
    long long s2 = 0;
    // initially all apples in group 2
    int n; cin >> n;
    vector<long long> p(n);
    for(auto& pi : p) 
    {
        cin >> pi;
        s2 += pi;
    }

    // bit mask to keep track of apple groups
    unsigned int groups = 0;

    long long lowest = s2;
    generate(0, p, groups, s1, s2, lowest);
    cout << lowest;
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