#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <string>
#include <unistd.h>
#include <limits>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_elements, n_selected;
    long long el, sum0, sum1, min0;
    sum0 = sum1 = 0ll;

    cin >> n_elements;
    n_selected = n_elements/2;
    min0 = LLONG_MAX;

    for(int i=0; i<n_elements; i++)
    {
        cin >> el;
        if (i%2 == 0)
        {
            sum0 += el;
            if (el <  min0) min0 = el;
        }
        else sum1 += el;
    }
    
    cout << max(sum0-min0, sum1) << endl;
    return 0;
}
