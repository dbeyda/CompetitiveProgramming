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
    string s;
    cin >> s;
    int count = 0;
    for(int i=0; i<n-1; i += 2)
    {
        if (s[i] == s[i+1])
        {
            s[i] = s[i] == 'a' ? 'b' : 'a';
            count++;
        }
    }
    cout << count << '\n' << s << '\n';
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
