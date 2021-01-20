#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

long long mod = 998244353;



void solve()
{
    string s;
    cin >> s;

    int open1 = 0;
    int open2 = 0;
    int moves = 0;

    for(auto& c : s)
    {
        if (c == '(')
            ++open1;
        else if (c == '[')
            ++open2;
        else if (c == ')' && open1)
        {
            --open1;
            ++moves;
        }
        else if (c == ']' && open2)
        {
            --open2;
            ++moves;
        }
    }
    cout << moves << '\n';
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