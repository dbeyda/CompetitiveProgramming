#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases, m, n;
    cin >> n_cases;

    while(n_cases--)
    {
        cin >> n >> m;
        if (n % m == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}