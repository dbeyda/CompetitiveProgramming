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
    vector<char> stones(n);
    int whites = 0;
    for(auto& s : stones)
    {
        cin >> s;
        if (s == 'W')
            whites++;
    }

    // suppose an ordering of RRRR...RWWW...W, count number of whites inside R partition
    int swaps = 0;
    for(int i=0; i<n-whites; i++)
        if (stones[i] == 'W')
            swaps++;
    cout << swaps << '\n';
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
