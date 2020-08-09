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
    int spent = 0;
    while (n >= 10)
    {
        int spentNow = n - n % 10;
        spent += spentNow;
        n = n - spentNow + spentNow/10;
    }
    spent += n;
    cout << spent << '\n';
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
