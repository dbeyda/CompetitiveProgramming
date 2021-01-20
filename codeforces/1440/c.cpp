#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


int fix(int i, int j, vector<string>& table, vector<vector<int>>& ops)
{
    int is[] = {i, i+1};
    int js[] = {j, j+1};
    int count = 0;

    for(auto ii : is)
        for(auto jj : js)
            if (table[ii][jj] == '1')
            {
                ++count;
                table[ii][jj] = '0';
            }

    if (count == 0) return 0;
    if (count == 1) return 3;
    if (count == 2) return 2;
    if (count == 3) return 1;
    if (count == 4) return 4;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> table(n);
    for(auto& s : table) cin >> s;

    int limn = n % 2 ? n-1 : n;
    int limm = m % 2 ? m-1 : m;
    vector<vector<int>> ops;
    
    for(int i=0; i < limn; i+=2)
        for(int j=0; j < limm; j+=2)
            fix(i, j, table, ops);
    if (n % 2)
        for(int j=0; j < limm; j+=2)
            fix(n-2, j, table, ops);
    if (m % 2)
        for(int i=0; i < limn; i+=2)
            fix(i, m-2, table, ops);
    
    cout << ops.size() << '\n';
    for(auto& op : ops)
    {
        for(auto& el : op)
            cout << el << " ";
        cout << '\n';
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
    cin >> t;
    for(int it=1; it<=t; it++)
        solve();
    return 0;
}