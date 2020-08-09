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
        double h, c, t;
        cin >> h >> c >> t;

        double avg = (h + c) / 2.0;
        if (t <= avg)
        {
            cout << 2 << '\n';
            continue;
        }
        if (t >= h)
        {
            cout << 1 << '\n';
            continue;
        }

        long long cups = 1;
        double totalTemp = h;
        double currTemp = h;
        double closestTemp = h;

        while(abs(t - closestTemp) >= abs(t - currTemp))
        {
            cups+=2;
            totalTemp += h + c;
            currTemp = totalTemp / (double)cups;
            if (abs(t-closestTemp) > abs(t - currTemp))
                closestTemp = currTemp;
        }
        // cout << cups-2 << " / temp = " << (totalTemp - h - c) / (cups-2)<< '\n';
        cout << cups-2 << '\n';
    }
    return 0;
}