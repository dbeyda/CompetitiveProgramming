#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    list<int> zeroEnded;
    list<int> oneEnded;
    vector<int> groupIds;
    //vector<vector<char>> groups;
    //groups.clear();

    int numGroups = 0;

    for(auto& i : s)
    {
        if (i == '0' && (oneEnded.size() > 0))
        {
            int idx = oneEnded.front();
            zeroEnded.push_front(idx);
            oneEnded.pop_front();
            groupIds.push_back(idx);
        }
        else if (i == '1' && (zeroEnded.size() > 0))
        {
            int idx = zeroEnded.front();
            oneEnded.push_front(idx);
            zeroEnded.pop_front();
            groupIds.push_back(idx);
        }
        else
        {
            numGroups++;
            groupIds.push_back(numGroups);
            if (i == '1') oneEnded.push_back(numGroups);
            else zeroEnded.push_back(numGroups);
        }
    }
    cout << numGroups << '\n';
    for(auto& g : groupIds)
        cout << g << " ";
    cout << '\n';

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nCases;
    cin >> nCases;

    while(nCases--)
        solve();

    return 0;
}
