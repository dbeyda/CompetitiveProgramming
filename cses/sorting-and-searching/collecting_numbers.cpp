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
    vector<long long> v(n);
    for(auto& vi : v) cin >> vi;

    vector<long long> seq;
    for(auto& vi : v)
    {
        if(seq.size() == 0)
        {
            seq.push_back(vi);
            continue;
        }

        // find best seq
        int bestSeqIdx = -1;
        for(int i=0; i<seq.size(); ++i)
            if(seq[i] < vi)
            {
                if (bestSeqIdx == -1) bestSeqIdx = i;
                else if(seq[i] > seq[bestSeqIdx]) bestSeqIdx = i;
            }
        
        // insert into seq
        if(bestSeqIdx == -1) seq.push_back(vi);
        else seq[bestSeqIdx] = vi;
    }

    cout << seq.size();
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