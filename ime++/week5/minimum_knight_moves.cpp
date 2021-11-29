#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

constexpr pair<int, int> moves[8] = 
{
    {-2, -1},
    {-2, 1},
    {2, -1},
    {2, 1},
    {-1, -2},
    {-1, 2},
    {1, -2},
    {1, 2}
};

bool validateCoord(pair<int, int>& p)
{
    return (p.first >= 0 && p.first <= 7)
        && (p.second >= 0 && p.second <= 7);
}

void solve()
{
    string startString, endString;
    cin >> startString >> endString;
    pair<int, int> startPos = make_pair(
        startString[0] - 'a',
        startString[1] - '1'
    );
    pair<int, int> endPos = make_pair(
        endString[0] - 'a',
        endString[1] - '1'
    );

    bool visited[8][8];
    memset(visited, false, sizeof(bool)*64);

    vector<queue<pair<int, int>>> vq(1);
    int level = 0;
    vq[level].push(startPos);
    visited[startPos.first][startPos.second] = true;
    while(!vq[level].empty())
    {
        // create new level
        if(vq.size()-1 == level) vq.push_back({});

        // add neighbours to new queue in the new level
        auto pos = vq[level].front(); vq[level].pop();
        // cout << "Processing " << pos.first << ", " << pos.second << endl;
        if(pos == endPos)
        {
            cout << level << endl;
            break;
        }
        for(auto& move : moves)
        {
            pair<int, int> newpos = make_pair(
                pos.first+move.first,
                pos.second+move.second
            );
            if (validateCoord(newpos) && !visited[newpos.first][newpos.second])
            {
                vq[level+1].push(newpos);
                visited[newpos.first][newpos.second] = true;
            }
        }

        // go to next level if needed
        if(vq[level].empty() && !vq[level+1].empty())
            level++;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w+", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // setup();
    long long t=1;
    cin >> t;
    for(int it=1; it<=t; it++)
        solve();
    return 0;
}