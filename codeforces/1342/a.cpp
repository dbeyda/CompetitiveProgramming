#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n_cases, x, y, a, b;
    cin >> n_cases;

    while(n_cases--)
    {
        cin >> x >> y;
        cin >> a >> b;
        long long minimum_spent = 0;

        if (2*a < b)
            minimum_spent += abs(x-y)*a + 2*min(x, y)*a;
        else
            minimum_spent+= abs(x-y)*a + min(x, y)*b;
        
        cout << minimum_spent << endl;
    }
    return 0;
}