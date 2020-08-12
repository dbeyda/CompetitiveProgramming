#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    long long r, g, b, w;
    cin >> r >> g >> b >> w;
    int paritySum = !!(r%2) + !!(g%2) + !!(b%2) + !!(w%2);
    if (paritySum <= 1)
        cout << "Yes\n";
    else if (!!(r%2) + !!(g%2) + !!(b%2) == 3 && r && g && b)
        cout << "Yes\n";
    else if (paritySum == 3 && (w%2) && r && g && b)
        cout << "Yes\n";
    else
        cout << "No\n";
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
