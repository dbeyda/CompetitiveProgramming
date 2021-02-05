#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


void printSet(multiset<long long>& s, string name)
{
    cout << name << ' ';
    for(auto& i : s) cout << i << " ";
    cout << endl;
}

inline long long getCost(multiset<long long>& below, multiset<long long>& above, long long sumBelow, long long sumAbove)
{
    long long median = *below.rbegin();
    return (sumAbove - median * above.size()) + (median * below.size() - sumBelow);
}


void solve()
{
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for(auto& vi : v) cin >> vi;

    long long sumAbove = 0;
    long long sumBelow = 0;
    multiset<long long> above;
    multiset<long long> below;
    for(int i=0; i<k; ++i)
    {
        above.insert(v[i]);
        sumAbove += v[i];
    }
    
    for(int i=0; i<(k+1)/2; ++i)
    {
        sumBelow += *above.begin();
        sumAbove -= *above.begin();
        below.insert(*above.begin());
        above.erase(above.begin());
    }
    cout << getCost(below, above, sumBelow, sumAbove) << ' ';
    for(int i=k; i<n; ++i)
    {
        long long& toAdd = v[i];
        long long& toRemove = v[i-k];

        auto it = above.find(toRemove);
        if(it != above.end())
        {
            sumAbove -= toRemove;
            above.erase(it);
        }
        else
        {
            sumBelow -= toRemove;
            it = below.find(toRemove);
            below.erase(it);
        }

        if(!below.empty() && *below.rbegin() > toAdd)
        {
            below.insert(toAdd);
            sumBelow += toAdd;
        }
        else
        {
            above.insert(toAdd);
            sumAbove += toAdd;
        }

        // balance both sets
        while(below.size() < above.size())
        {
            sumBelow += *above.begin();
            sumAbove -= *above.begin();
            below.insert(*above.begin());
            above.erase(above.begin());
        }
        while(below.size() > above.size()+1)
        {
            sumAbove += *below.rbegin();
            sumBelow -= *below.rbegin();
            above.insert(*below.rbegin());
            below.erase(prev(below.end()));
        }
        cout << getCost(below, above, sumBelow, sumAbove) << ' ';
    }
    cout << endl;
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