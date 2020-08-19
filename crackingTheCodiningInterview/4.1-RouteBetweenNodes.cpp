/* Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a
route between two nodes.

Additionally, we are keeping track of the curent BFS level, so we can return the distance.

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int search(vector<vector<int>>& adjList, int start, int end)
{
    if (start == end) return true;
    vector<int> visited(adjList.size(), 0);
    vector<queue<int>> q(adjList.size());
    int level = 0;
    q[0].push(start);
    visited[start] = 1;
    while(level < adjList.size() && !q[level].empty())
    {
        int current = q[level].front();
        // visit(current);
        if (current == end) return level;
        for(auto& n : adjList[current])
        {
            if (visited[n]) continue;
            visited[n] = 1;
            q[level+1].push(n);
        }
        q[level].pop();
        if(q[level].empty()) ++level;
    }
    return -1;
}

int main()
{
    vector<vector<int>> adjList = {
        {3, 2},
        {2},
        {0, 1, 3},
        {0, 2},
        {5, 6},
        {4, 6, 7},
        {4, 5},
        {5}
    };

    int start = 0;
    int end = 1;

    cout << "Searching path between " << start << " and " << end << "...\n";
    int distance = search(adjList, start, end);
    if(distance >= 0) cout << "Found minimum path with distance " << distance << "\n";
    else cout << "Path not found.\n";


    return 0;
}