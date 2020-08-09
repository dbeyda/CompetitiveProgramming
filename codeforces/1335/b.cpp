#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases, n, a, b;
    cin >> n_cases;

    while(n_cases--)
    {
        // solve one test case
        cin >> n >> a >> b;
        for(int i=0; i<n; i++)
        {
           char output = 'a' + i%b;
           cout << output;

        }
        cout << '\n';
    }
    return 0;
}