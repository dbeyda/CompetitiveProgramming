#include <iostream>
#include <vector>

using namespace std;

void getSubsets(vector<int>& v, vector<vector<int>>& sets)
{
    sets.push_back({});
    for(auto& i : v)
    {
        int setsSize = sets.size();
        for(int s=0; s<setsSize; ++s)
        {
            vector<int> newSet = sets[s];
            newSet.push_back(i);
            sets.push_back(newSet);
        }
    }
}

void getSubsets(vector<int>& v)
{
    vector<vector<int>> sets;
    getSubsets(v, sets);
    for(auto& set : sets)
    {
        cout << "{ ";
        for(auto& elem : set) cout << elem << " ";
        cout << "}\n";
    }
}

int main()
{
    int len;
    cin >> len;
    vector<int> v(len);
    for(auto& i : v)
        cin >> i;
    getSubsets(v);
    return 0;
}
