#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void bfsComponents(int start, int componentId, vector<vector<int>> adj, vector<int>& visited)
{
    queue<int> q;
    visited[start] = componentId;
    q.push(start);
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        for(int i=0; i < adj[current].size(); i++)
        {
            int neighbor = adj[current][i];
            if (!visited[neighbor])
            {
                visited[neighbor] = componentId;
                q.push(neighbor);
                //result.push_back(make_pair(current, neighbor));
            }
        }
    }
}

void bfs(int start, vector<vector<int>> adj)
{
    vector<int> visited(adj[0].size(), 0);
    queue<int> q;
    visited[start] = 1;
    q.push(start);
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
                cout << current+1 << ' ' << neighbor+1 << endl;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nCases = 1;

    while(nCases--)
    {
        int n, m, d;
        cin >> n >> m >> d;

        vector<vector<int>> adj(n);
        vector<vector<int>>adj2(n);
        for(int i=0; i<m; i++)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(a != 0 && b != 0)
            {
                adj2[a].push_back(b);
                adj2[b].push_back(a);
            }
        }

        if (d > adj[0].size())
        {
            cout << "NO" << endl;
            return 0;
        }

        vector<int> visited(n, 0);
        int components = 0;
        for(auto i : adj[0])
            if (!visited[i])
            {
                components++;
                bfsComponents(i, components, adj2, visited);
            }

        for(auto i : adj[0])
            cout << "Component of node " << i << " = " << visited[i] << endl;

        if (d < components)
        {
            cout << "NO" << endl;
            return 0;
        }

        if (d == adj[0].size())
        {
            cout << "YES" << endl;
            bfs(0, adj);
            return 0;
        }

        // we must remove adj[0].size() - d edges
        vector<list<int>> componentGroups(components);
        for(int i=0; i<adj[0].size(); i++)
        {
            int neighbor = adj[0][i];
            componentGroups[visited[neighbor]].push_back(neighbor);
        }

        vector<int> selectedZeroNeighbors;
        for(int i=0; i<d; i++)
        {
            if (componentGroups.size())
            {
                selectedZeroNeighbors.push_back(componentGroups[i].front());
                componentGroups[i].pop_front();


            }
        }
    }

    return 0;
}
