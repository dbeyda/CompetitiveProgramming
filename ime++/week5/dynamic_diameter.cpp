#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

void longestBFS(int startPos, int nodes, vector<vector<int>>& adj, set<int>& longest, int& distance)
{
    list<queue<int>> q(2);
    bool visited[nodes];
    memset(visited, 0, sizeof(bool)*nodes);
    int level = 0;
    q.front().push(startPos);
    visited[startPos] = true;
    while(!q.front().empty())
    {
        // create new level
        if(q.size() < 2) q.push_back({});

        // add neighbours to new queue in the new level
        auto curr = q.front().front(); q.front().pop();
        longest.insert(curr);

        for(auto& next : adj[curr])
        {
            if (!visited[next])
            {
                q.back().push(next);
                visited[next] = true;
            }
        }
        // go to next level if needed
        if(q.front().empty() && !q.back().empty())
        {
            q.pop_front();
            q.push_back({});
            longest.clear();
            level++;
            distance = level;
        }
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

    set<int> longest;
    int distance = 0;
    longestBFS(0, nodes, adj, longest, distance);
    
    int newstart = *longest.begin();
    longest.clear();
    distance = 0;
    longestBFS(newstart, nodes, adj, longest, distance);
    longest.insert(newstart);
    
    for(int i=0; i<nodes; ++i)
    {
        if(longest.count(i))
            cout << distance+1 << endl;
        else cout << distance << endl;
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