#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nCases = 1;

    while(nCases--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n);
        for(int i=0; i<m; i++)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        // get max degree node
        int maxIdx = 0;
        int maxDegree = adj[0].size();
        for(int i=0; i<n; i++)
        {
            if(adj[i].size() > maxDegree)
            {
                maxDegree = adj[i].size();
                maxIdx = i;
            }
        }

        vector<pair<int, int>> result;
        // maximum node is the start of the bfs
        vector<int> visited(n, 0);
        queue<int> q;
        //cout << "Max id = " << maxIdx+1 << endl;
        visited[maxIdx] = true;
        q.push(maxIdx);
        while(!q.empty())
        {
            int current = q.front();
            q.pop();
            for(int i=0; i < adj[current].size(); i++)
            {
                int neighbor = adj[current][i];
                if (!visited[neighbor])
                {
                    visited[neighbor] = 1;
                    q.push(neighbor);
                    result.push_back(make_pair(current, neighbor));
                }
            }
        }
        for(auto& p : result)
            cout << p.first+1 << ' ' << p.second+1 << endl;

    }

    return 0;
}
