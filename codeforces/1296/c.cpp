#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

void solve()
{
    int n;
    cin >> n;
    pair<int, int> loop;
    bool foundLoop = false;
    pair<int, int> currPos = make_pair(0, 0);
    map<pair<int, int>, int> m;
    string moves;
    cin >> moves;
    for (int i = 0; i < n; ++i)
    {
        m[currPos] = i;

        auto &move = moves[i];        
        if (move == 'R') currPos.first++;
        else if (move == 'L') currPos.first--;
        else if (move == 'U') currPos.second++;
        else if (move == 'D') currPos.second--;
        // cout << "___________\n";
        // cout << "NewPos: " << currPos.first << ", " << currPos.second << '\n';
        auto it = m.find(currPos);
        if (it != m.end())
        {
            // cout << "currPos last seen on step " << it->second << '\n';
            int newLoopSize = i - it->second + 1;
            int oldLoopSize = loop.second - loop.first + 1;
            if (!foundLoop || newLoopSize < oldLoopSize)
            {
                loop = make_pair(it->second, i);
                foundLoop = true;
            }
        }
        // cout << "m[" << currPos.first << "," << currPos.second << "] = " << i << '\n';
    }
    // cout << "=========\nFinal Ans:\n";
    if(foundLoop) cout << loop.first+1 << " " << loop.second+1 << "\n";
    else cout << "-1\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w+", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
        solve();
    return 0;
}