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
    bool allEqual = true;
    long long prev = 0;
    long long num = 0;
    for(int i=0; i<n; i++)
    {
        if (i == 0) cin >> prev;
        else
        {
            cin >> num;
            if (num != prev)
                allEqual = false;
            prev = num;
        }
    }

    if(allEqual) cout << n << "\n";
    else cout << "1\n";
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
