#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <string>
#include <unistd.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_elements, a, b;
    int max_a = 0;

    cin >> n_elements;

    for(int i=0; i<n_elements; i++)
    {
        cin >> b;
        a = b + max_a;
        cout << a << " ";
        max_a = max(a, max_a);
    }
    
    cout << '\n';
    return 0;
}
