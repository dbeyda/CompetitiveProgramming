#include <iostream>
#include <vector>

using namespace std;

void getSubsets(vector<int>& v, vector<vector<int>>& sets, int end)
{
    if(end < 0)
    {
        sets.push_back(vector<int>());
        return;
    }
    getSubsets(v, sets, end-1);
    int setSize = sets.size();
    for(int i=0; i < setSize; i++)
    {
        vector<int> setWithLast = sets[i];
        setWithLast.push_back(v[end]);
        sets.push_back(setWithLast);
    }
}

void getSubsets(vector<int>& v)
{
    vector<vector<int>> sets;
    getSubsets(v, sets, v.size()-1);
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
