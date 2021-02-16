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
    vector<string> words(n);
    for(auto& w : words) cin >> w;

    map<string, set<char>> groups;
    for(auto& w : words) groups[w.substr(1)].insert(w[0]);

    long long total = 0;

    for(auto it = groups.begin(); it != prev(groups.end()); it++)
        for(auto jt = next(it); jt != groups.end(); jt++)
        {
            auto& set1 = it->second;
            auto& set2 = jt->second;
            long long num1 = 0;
            long long num2 = 0;
            for(auto& letter1 : set1)
                if(set2.count(letter1) == 0)
                    num1++;
            for(auto& letter2 : set2)
                if(set1.count(letter2) == 0)
                    num2++;
            total += num1 * num2;
        }
    cout << total * 2 << endl;
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