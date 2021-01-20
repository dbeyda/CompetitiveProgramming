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
    string s; cin >> s;
    if (n == 1)
    {
        cout << "1\n1\n";
        return;
    }

    vector<int> ans;
    ans.resize(n);
    vector<char> last;
    last.push_back('a');

    for(int i=0; i<n; ++i)
    {
        bool colored = false;
        for(int c=0; c<last.size(); ++c)
        {
            if (s[i] >= last[c])
            {
                last[c] = s[i];
                ans[i] = c+1;
                colored = true;
                break;
            }
        }
        if(!colored)
        {
            last.push_back(s[i]);
            ans[i] = last.size();
        }
    }
    cout << last.size() << '\n';
    for(auto& c : ans) cout << c << " ";
    cout << '\n';
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