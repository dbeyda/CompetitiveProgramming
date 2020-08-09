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

    int size = n/2;
    if (size % 2 != 0) cout << "NO\n";
    else
    {
        cout << "YES\n";
        for(int i=1; i<=size; i++) cout << 2*i << ' ';
        for(int i=1; i<=size/2; i++) cout << 2*i - 1 << ' ';
        for(int i=size/2+1; i<=size; i++) cout << 2*i + 1 << ' ';
        cout << '\n';
    }
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
