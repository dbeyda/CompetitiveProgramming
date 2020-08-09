#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases, arr_len, arr_item;
    cin >> n_cases;

    while(n_cases--)
    {

        cin >> arr_len;
        vector <int> a(arr_len);

        for(int i=0; i < arr_len; i++)
        {
            cin >> arr_item;
            a[i] = arr_item;
        }

        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        for (auto &x: a) cout << x << " ";
        cout << '\n';
    }

    return 0;
}
