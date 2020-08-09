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
    int n, k;
    long long arr_item;
    bool ok = true;

    int basek[65];


    cin >> n_cases;

    while(n_cases--)
    {
        memset(basek, 0, 65 * sizeof(int));
        ok = true;
        cin >> n >> k;

        for(int i=0; i < n; i++)
        {
            cin >> arr_item;
            // cout << "Got new array item: " << arr_item << "\n";
            for(int j=0; arr_item != 0; j++)
            {
                basek[j] += arr_item % k;
                arr_item /= k;
                // cout << "Arr item divided into " << arr_item << "\n";
            }
        }

        // cout << "verifying...";
        // for (int x: basek) {
        //     cout << x << " ";
        // }
        // cout << "\n";

        for (auto x: basek) {
            if (x > 1){
                ok = false;
                break;
            }
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
