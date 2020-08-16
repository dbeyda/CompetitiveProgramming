#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

bool isRainy(char c)
{
    return c == 'R';
}

void solve()
{
    string s;
    cin >> s;
    if(isRainy(s[1]))
    {
        if(isRainy(s[0]) && isRainy(s[2])) cout << 3;
        else if(isRainy(s[0]) || isRainy(s[2])) cout << 2;
        else cout << 1;
    }
    else if(isRainy(s[0]) || isRainy(s[2])) cout << 1;
    else cout << 0;
    cout << '\n';
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
