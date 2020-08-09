#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int getTeamsNum(vector<int>& w, int s)
{
    int teams = 0;
    map<int, int> seen;
    for(auto& weight : w)
    {
        if(seen.count(s-weight) && seen[s-weight] > 0)
        {

            teams++;
            seen[s-weight]--;
        }
        else
        {
            if(seen.count(weight)) seen[weight]++;
            else seen[weight] = 1;
        }
    }
    return teams;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> w(n);
    for(auto& num : w)
        cin >> num;

    int maxTeams = 0;
    for(int s=2; s<=100; s++)
    {
        int teams = getTeamsNum(w, s);
        maxTeams = max(teams, maxTeams);
    }

    cout << maxTeams << '\n';

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
