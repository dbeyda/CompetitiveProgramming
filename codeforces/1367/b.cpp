#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    int n;
    cin >> n;
    int x;
    int wrongEven = 0;
    int wrongOdd = 0;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        if ((i & 1) != (x & 1))
        {
            if (i & 1) wrongEven++;
            else wrongOdd++;
        }
    }
    if (wrongEven == wrongOdd)
        cout << wrongEven << '\n';
    else
        cout << -1 << '\n';
    

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases;
    cin >> n_cases;

    while(n_cases--)
        solve();
    return 0;
}