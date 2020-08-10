#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    int c, r;
    cin >> c >> r;
    if (r - c >= 9) cout << 0;
    else cout << 1;
    int m = min(c, r);
    cout << " " << m/9 + !!(m%9) << '\n';
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
