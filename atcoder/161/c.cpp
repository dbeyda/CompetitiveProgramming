#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, new_n;
    cin >> n >> k;
    n = n % k;

    new_n = abs(n - k);
    if (new_n >= n)
        cout << n << endl;
    else
        cout << new_n << endl;
    return 0;
}
