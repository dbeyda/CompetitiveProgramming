/*
Build Order: You are given a list of projects and a list of dependencies (which is a list of pairs of
projects, where the second project is dependent on the first project). All of a project's dependencies
must be built before the project is. Find a build order that will allow the projects to be built. If there
is no valid build order, return an error.

EXAMPLE
Input:
projects: a, b, c, d, e, f
dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
Output: f, e, a, b, d, c
*/

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool topologicalSort(unordered_map<char, vector<char>>& adj, list<char>& top)
{
    // nodes with zero dependencies will be stored in readyToBuild
    list<char> readyToBuild;
    // count dependencies for each node
    unordered_map<char, int> numDependencies;

    // count dependencies for each node
    for(auto it = adj.begin(); it != adj.end(); ++it)
    {
        if (!numDependencies.count(it->first))
            numDependencies[it->first] = 0;

        for(auto& dependent : it->second)
            numDependencies[dependent]++;
    }

    // build set with nodes that have zero dependencies
    for(auto it = numDependencies.begin(); it != numDependencies.end(); ++it)
        if(it->second == 0)
            readyToBuild.push_back(it->first);

    while(readyToBuild.size())
    {
        char buildNext = readyToBuild.front();
        readyToBuild.pop_front();
        top.push_back(buildNext);
        cout << "building " << buildNext << endl;
        for(auto& dependent : adj[buildNext])
        {
            --numDependencies[dependent];
            if (numDependencies[dependent] == 0)
                readyToBuild.push_back(dependent);
        }
    }
    // if sizes are different, could not build every node
    return top.size() == adj.size();
}

int main()
{

    unordered_map<char, vector<char>> adj = {
        {'a', {'e'}},
        {'b', {'a', 'e'}},
        {'c', {'a'}},
        {'d', {'g'}},
        {'e', {}},
        {'f', {'c', 'b', 'a'}},
        {'g', {}}
    };

    list<char> top;
    bool sorted = topologicalSort(adj, top);
    if (sorted)
    {
        cout << "Topological sorting: ";
        for(auto& c : top)
            cout << c << " ";
        cout << endl;
    }
    else cout << "Could not find a topological sorting. Graph contains a cycle.\n";

    return 0;
}