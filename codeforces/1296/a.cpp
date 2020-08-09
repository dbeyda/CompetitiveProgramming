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
    int x;
    bool hasEven, hasOdd;
    hasEven = hasOdd = false;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        if (x%2) hasOdd = true;
        else hasEven = true;
    }

    if (n%2 == 0 && hasEven && hasOdd) cout << "YES\n";
    else if (n%2 && hasOdd) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nCases = 1;
    cin >> nCases;

    while(nCases--)
        solve();

    return 0;
}
