#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases;
    cin >> n_cases;

    while(n_cases--)
    {
        long long n, m;
        cin >> n >> m;

        if (n == 1) cout << 0 << '\n';
        else if (n == 2) cout << m << '\n';
        else cout << 2*m << '\n';
    }
    return 0;
}