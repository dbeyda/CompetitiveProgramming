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

        long long lights = 0;
        lights += n/2 * m;
        
        if (n%2)
            lights += (long long) ceil((float) m / 2.0);
        cout << lights << '\n';
    }
    return 0;
}