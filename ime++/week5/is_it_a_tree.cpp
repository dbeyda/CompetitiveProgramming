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
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> adj[nodes];
    int x, y;
    for(int i=0; i<edges; ++i)
    {
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // test 1: edges = nodes-1
    // cout << "nodes " << nodes << endl;
    // cout << "edges " << edges << endl;
    if(edges != nodes - 1)
    {
        cout << "NO" << endl;
        return;
    }

    // cout << "into test 2" << endl;
    // test 2: only one connected component
    int visited[nodes];
    memset(visited, 0, sizeof(int) * nodes);
    // dfs from each node
    int nvisit = 1;
    for(int i=0; i<nodes; ++i)
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
    if(nvisit == 2) cout << "YES" << endl;
    else cout << "NO" << endl;
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