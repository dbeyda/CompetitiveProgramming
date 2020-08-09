#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <string>
#include <unistd.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases;
    int n;
    cin >> n_cases;

    while(n_cases--)
    {
        cin >> n;
        
        if (n <= 1) {
            cout << -1 << '\n';
            continue;
        }

        cout << 2;
        for(int i=0; i<n-1; i++) {
            cout << 3;
        }
        cout << '\n';
    }

    return 0;
}
