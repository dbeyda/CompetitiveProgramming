#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);


void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> guest(n, 0);
    for(auto& g: guest)
        cin >> g;

    // dp will hold best cost up to i-th guest (including cost of tables)
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    unordered_map<int, int> newTable;
    int newTableCost;
    for(int i=1; i<=n; i++)
    {
        newTable.clear();                                       // start new table
        newTableCost = 0;                                       // new table with zero fights between guests
        for(int j=0; j<i; j++)
        {
            // new table with guests (i-j) to i
            newTable[guest[i-1-j]]++;                           // add guest to table
            if (newTable[guest[i-1-j]] == 2) newTableCost += 2; // increase table inneficiency if needed
            if (newTable[guest[i-1-j]] > 2) newTableCost++;  // increase table inneficiency if needed
            dp[i] = min(dp[i], newTableCost + k + dp[i-j-1]);   // update dp
        }
    }
    cout << dp[n] << '\n';
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
