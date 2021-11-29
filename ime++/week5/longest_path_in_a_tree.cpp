#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

void longestBFS(int startPos, int nodes, vector<vector<int>>& adj, int& longest, int& distance)
{
    vector<queue<int>> q(1);
    bool visited[nodes];
    memset(visited, 0, sizeof(bool)*nodes);
    int level = 0;
    q[level].push(startPos);
    visited[startPos] = true;
    while(!q[level].empty())
    {
        // create new level
        if(q.size()-1 == level) q.push_back({});

        // add neighbours to new queue in the new level
        auto curr = q[level].front(); q[level].pop();
        longest = curr;
        distance = level;

        for(auto& next : adj[curr])
        {
            if (!visited[next])
            {
                q[level+1].push(next);
                visited[next] = true;
            }
        }
        // go to next level if needed
        if(q[level].empty() && !q[level+1].empty())
            level++;
    }
}

void solve()
{
    int nodes;
    cin >> nodes;
    vector<vector<int>> adj(nodes);
    int x, y;
    for(int i=0; i<nodes-1; ++i)
    {
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int longest, distance;
    longestBFS(0, nodes, adj, longest, distance);
    longestBFS(longest, nodes, adj, longest, distance);
    cout << distance << endl;
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