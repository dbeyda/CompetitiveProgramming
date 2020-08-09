#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

bool tryCut(vector<int>& vec, long long maxHeight, long long maxCuts)
{
    long long cuts = 0;
    for(auto tree : vec)
        cuts += (tree-1)/maxHeight;
    return cuts <= maxCuts;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    int highest = -1;
    for(auto& tree : v)
    {
        cin >> tree;
        if (tree > highest)
            highest = tree;
    }

    int startHeight = 1;
    int endHeight = highest;
    bool start = tryCut(v, startHeight, k);

    if (start)
    {
        cout << 1 << "\n";
        return;
    }

    while(endHeight - startHeight > 1)
    {
        int middleHeight = (endHeight + startHeight) / 2;
        bool middle = tryCut(v, middleHeight, k);
        if (middle)
            endHeight = middleHeight;
        else
            startHeight = middleHeight;
    }
    cout << endHeight << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nCases = 1;
    // cin >> nCases;

    while(nCases--)
        solve();

    return 0;
}
