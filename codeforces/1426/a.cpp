#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);


void solve()
{
    int n, x;
    cin >> n >> x;
    if (n <= 2)
    {
        cout << 1 << "\n";
        return;
    }

    cout << 1 + (n-2)/x + ((n-2)%x > 0 ? 1 : 0)<< "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases = 1;
    cin >> n_cases;

    while(n_cases--) solve();
    return 0;
}