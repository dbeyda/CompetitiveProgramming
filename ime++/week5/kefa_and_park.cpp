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
    int n, m; cin >> n >> m;
    int cat[n], visited[n], ncats[n];
    memset(visited, 0, sizeof(int)*n);
    memset(ncats, 0, sizeof(int)*n);
    for(auto& c : cat) cin >> c;
    vector<int> adj[n];
    
    int x, y;
    for(int i=0; i<n-1; ++i)
    {
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans=0;
    // dfs
    stack<int> st;
    visited[0] = 1;
    ncats[0] = cat[0];
    if(ncats[0] <= m)
        st.push(0);
    while(!st.empty())
    {
        int curr = st.top(); st.pop();
        if(adj[curr].size() == 1 && visited[adj[curr].front()] && ncats[curr] <= m)
            ans++;
        else
            for(auto& a : adj[curr])
            {
                int acats = cat[a] * ncats[curr] + cat[a];
                if(!visited[a] && acats <= m)
                {
                    visited[a] = 1;
                    ncats[a] = acats;
                    st.push(a);
                }
            }
    }
    cout << ans << endl;

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