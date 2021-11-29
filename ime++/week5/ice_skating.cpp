#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

// find number of connected components
void solve()
{
    int n; cin >> n;
    vector<int> adj[n];
    map<int, vector<int>> xs;
    map<int, vector<int>> ys;
    int x, y;
    for(int i=0; i<n; ++i)
    {
        cin >> x >> y;
        x--; y--;
        if(!xs[x].empty())
        {
            auto next = xs[x].front();
            adj[i].push_back(next);
            adj[next].push_back(i);
        }
        if(!ys[y].empty())
        {
            auto next = ys[y].front();
            adj[i].push_back(next);
            adj[next].push_back(i);
        }
        xs[x].push_back(i);
        ys[y].push_back(i);
    }

    int visited[n];
    memset(visited, 0, sizeof(int) * n);
    // dfs from each node
    int nvisit = 1;
    for(int i=0; i<n; ++i)
    {
        if(visited[i]) continue;
        
        stack<int> st;
        st.push(i);
        visited[i] = nvisit;
        while(!st.empty())
        {
            int curr = st.top(); st.pop();
            for(auto& next : adj[curr])
                if(!visited[next])
                {
                    visited[next] = nvisit;
                    st.push(next);
                }
        }
        nvisit++;
    }
    
    cout << nvisit-2 << endl;
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