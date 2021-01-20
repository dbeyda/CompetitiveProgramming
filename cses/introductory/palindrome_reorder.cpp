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
    string original; cin >> original;
    unordered_map<char, long long> m;
    string ans;
    ans.resize(original.size());
    for(auto& c : original)
        m[c]++;
    
    long long odds = 0;
    for(auto it = m.begin(); it != m.end(); it++)
        if(it->second % 2) ++odds;
    
    if((original.size() % 2 == 0) && odds > 0) cout << "NO SOLUTION\n";
    else if ((original.size() % 2 == 1) && odds != 1) cout << "NO SOLUTION\n";
    else
    {
        long long start = 0;
        long long end = original.size()-1;
        for(auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second % 2)
            {
                ans[original.size()/2] = it->first;
                it->second--;
            }
            while(it->second > 0)
            {
                ans[start] = ans[end] = it->first;
                ++start;
                --end;
                it->second -= 2;
            }
        }
        cout << ans << '\n';
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