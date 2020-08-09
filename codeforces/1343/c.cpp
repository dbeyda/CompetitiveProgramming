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

    long long current, maximum, sum = 0;
    cin >> maximum;
    n--;

    while(n--)
    {
        cin >> current;
        // current has the same signal as maximum
        if (current * maximum > 0)
        {
            maximum = max(maximum, current);
        }
        else
        {
            sum += maximum;
            maximum = current;
        }
    }
    sum += maximum;
    cout << sum << endl;
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
