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
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;

        if(!n2 && !n0 && n1)
        {
            for(int i=0; i<n1+1; i++)
                cout << (i%2 == 0 ? 1 : 0);
            cout << '\n';
        }
        else if(n2 && !n0 && n1)
        {
            for(int i=0; i<n2+1; i++)
                cout << 1;
            cout << 0;
            n1--;
            for(int i=0; i<n1; i++)
                cout << (i%2 == 0 ? 1 : 0);
            cout << '\n';
        }
        else
        {
            if (n2)
                for(int i=0; i<n2+1; i++)
                    cout << 1;
            if (n0)
                for(int i=0; i<n0+1; i++)
                    cout << 0;
            if(n2 && n0) n1--;
            if(n1)
            {
                cout << 1;
                n1--;
                for(int i=0; i<n1; i++)
                    cout << (i%2 == 0 ? 0 : 1);
            }
            cout << '\n';
        }
    }
    return 0;
}