#include <bits/stdc++.h>
#include <iostream>

using namespace std;

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
        cout << (n-1)/2 << '\n';
    }
    return 0;
}