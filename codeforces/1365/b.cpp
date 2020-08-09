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
        int n;
        cin >> n;
        bool alreadyOrdered = true;
        int last = 0;
        // reading a
        for(int i=0; i<n; i++) {
            int a;
            cin >> a;
            if (i != 0 && a < last)
                alreadyOrdered = false;
            last = a;
        }
        // read b
        bool has0 = false, has1 = false;
        for(int i=0; i<n; i++) {
            int b;
            cin >> b;
            if(b) has1 = true;
            else has0 = true;
        }
        if(alreadyOrdered)
        {
            cout << "Yes\n";
            continue;
        }
        if (has0 && has1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}