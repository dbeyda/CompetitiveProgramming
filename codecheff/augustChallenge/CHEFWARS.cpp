#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    int h, p;
    cin >> h >> p;
    if (h <= p)
    {
        cout << 1 << '\n';
        return;
    }
    int aux = p;
    int resto = 0;
    while(aux > 0)
    {
        resto += aux % 2;
        aux /= 2;
    }
    cout << (h <= 2*p - resto) << '\n';
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
