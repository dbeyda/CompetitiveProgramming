#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

/*
começa em max(a, b)
pula de multiplos de (a e b) até mult(a, b) + max(a, b)
*/

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int n_cases;
    cin >> n_cases;
    while(n_cases--)
    {
        int a, b, q;
        cin >> a >> b >> q;
        while (q--)
        {
            long long l, r;
            cin >> l >> r;
            int i=l;
            if(i < max(a, b))
                i = max(a, b);
            int count = 0;
            while(i <= r)
            {
                if (((i%a)%b) != ((i%b)%a))
                    count++;
                if ((i % a == 0) && (i % b == 0))
                    i+= max(a, b);
                else
                    i++;
            }
            cout << count << " ";
        }
        cout << endl;
    }
    return 0;
}
