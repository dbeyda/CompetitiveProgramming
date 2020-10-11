#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

/*
busca bin achar o minimo da função onde K = lower bound

f(inc) = inc + K/inc

min x + K/x where x > =1

f'(x) = 0
1 = k/x²
k = x²
x = sqrt(k)

*/

void solve()
{
    long long n;
    cin >> n;
    long long inc = ceil(sqrt(n));
    cout << -2 + inc + (long long) ceil((double) n/inc) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases = 1;
    cin >> n_cases;

    while(n_cases--) solve();
    return 0;
}