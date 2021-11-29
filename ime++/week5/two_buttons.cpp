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
    int start, target;
    cin >> start >> target;
    if(start == target)
    {
        cout << 0 << endl;
        return;
    }

    // BFS
    vector<bool> visited(2*target + start, false);
    queue<pair<int, int>> q; // <currentValue, moves> 
    visited[start] = true;
    q.push(make_pair(start, 0));
    while(true)
    {
        auto p = q.front();
        q.pop();
        // cout << "Processing " << p.first << endl;

        if(p.first-1 == target || p.first * 2 == target)
        {
            cout << p.second+1 << endl;
            break;
        }
        if(target > p.first && !visited[p.first*2])
        {
            q.push(make_pair(p.first*2, p.second+1));
            visited[p.first*2] = true;
        }
        if(p.first > 0 && !visited[p.first-1])
        {
            q.push(make_pair(p.first-1, p.second+1));
            visited[p.first-1] = true;
        }
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