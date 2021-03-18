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
    int n, nOps; cin >> n >> nOps;

    vector<int> v(n+1, -1);
    vector<int> positions(n+1, -1);
    for(int i=1; i<=n; ++i)
    {
        cin >>  v[i];
        positions[v[i]] = i;
    }

    vector<pair<int, int>> ops (nOps);
    for(auto& op : ops) cin >> op.first >> op.second;

    int passes = 1;
    for(int i=2; i<=n; ++i)
        if(positions[i] < positions[i-1])
            ++passes;

    for(auto& op : ops)
    {
        int firstValue = v[op.first];
        int secondValue = v[op.second];

        // removing a
        if(firstValue != 1 && positions[firstValue] < positions[firstValue-1])
            --passes;
        if(firstValue != n && positions[firstValue+1] < positions[firstValue])
            --passes;
        // removing b
        if(secondValue != 1
            && secondValue-1 != firstValue
            && positions[secondValue] < positions[secondValue-1])
            --passes;
        if(secondValue != n
           && secondValue+1 != firstValue
           && positions[secondValue+1] < positions[secondValue])
            --passes;

        swap(positions[firstValue], positions[secondValue]);
        swap(v[op.first], v[op.second]);
        swap(firstValue, secondValue);
        
        // adding a
        if(firstValue != 1 && positions[firstValue] < positions[firstValue-1])
            ++passes;
        if(firstValue != n && positions[firstValue+1] < positions[firstValue])
            ++passes;
        // adding b
        if(secondValue != 1
            && secondValue-1 != firstValue
            && positions[secondValue] < positions[secondValue-1])
            ++passes;
        if(secondValue != n
           && secondValue+1 != firstValue
           && positions[secondValue+1] < positions[secondValue])
            ++passes;
        cout << passes << endl;
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