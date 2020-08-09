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
        int n, k;
        cin >> n >> k; 
        if (k == 1)
        {
            cout << "yes\n";
            cout << n << "\n";
            continue;
        }
        if (k > n)
        {
            cout << "no\n";
            continue;
        }
        // tentativa impar
        int last = n - (k-1);
        if (last > 0 && last % 2 == 1)
        {
            cout << "yes\n";
            for(int i=0; i<k-1; i++)
                cout << 1 << ' ';
            cout << last << '\n';
            continue;
        }
        // tentativa par
        last = n - (k-1)*2;
        if (last > 0 && n%2 == 0)
        {
            cout << "yes\n";
            for(int i=0; i<k-1; i++)
                cout << 2 << ' ';
            cout << last << '\n';
            continue;
        }

        cout << "no\n";
    }
    return 0;
}