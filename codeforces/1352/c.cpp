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
        long long n, k;
        cin >> n >> k;
        /*
        4 12

        ncicles = 12 / 3 = 4
        offset = 12 % 3 = 0
        return 4 * 4 + 0


        */
        long long ncicles = (k-1) / (n-1);
        long long offset = k - ncicles*(n-1);

        cout << ncicles * n + offset << '\n';
    }
    return 0;
}