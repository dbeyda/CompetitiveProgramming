#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    int k;
    cin >> k;
    int x = 7 % k;
    int it = 1;
    vector<char> seen(k, 0);
    while (it < 1e6 && x != 0)
    {
        it++;
        x = ((x%k) * (10%k)) % k;
        x = (x + 7%k)%k;
        if(seen[x]) break;
        seen[x] = 1;

    }
    if (x == 0)
        cout << it << '\n';
    else
        cout << -1 << '\n';
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
