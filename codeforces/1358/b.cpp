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
        long long n;
        cin >> n;

        vector<int> a(n);
        for(int& ai : a)
            cin >> ai;

        sort(a.begin(), a.end());
        int grannies = 1;
        int called = 0;
        for(int i=0; i<n; i++)
        {
            if(a[i] <= grannies + called)
            {
                grannies += called + 1;
                called = 0;
            }
            else
                called++;
        }
        cout << grannies << '\n';

    }
    return 0;
}