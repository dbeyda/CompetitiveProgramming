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

    int n_elements, n_selected;
    long long el, sum0, sum1;

    priority_queue<long long> elements0, elements1;

    cin >> n_elements;
    n_selected = n_elements/2;

    for(int i=0; i<n_elements; i++)
    {
        cin >> el;
        if (i%2 == 0)
            elements0.push(el);
        else
            elements1.push(el);
    }

    sum0 = sum1 = 0ll;
    
    for(int i=0; i<n_selected; i++)
    {
        sum0 += elements0.top();
        elements0.pop();

        sum1 += elements1.top();
        elements1.pop();
    }

    cout << "n_selected = " << n_selected << endl;
    cout << max(sum0, sum1) << endl;
    return 0;
}
