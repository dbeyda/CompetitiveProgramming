#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int getMaxMultiple(int x, int y)
{
    return x * (y/x);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_tests, n, d, answer;
    vector<int> h; 
    cin >> n_tests;

    for(int i=0; i<n_tests; i++)
    {
        // solve each test case
        h.clear();
        cin >> n >> d;
        answer = d;
        for(int j=0; j<n; j++)
        {
            int el;
            cin >> el;
            h.push_back(el);
        }

        for(int j=n-1; j>=0; j--)
            answer = getMaxMultiple(h[j], answer);
        cout << "Case #" << i+1 << ": " << answer << endl;
    }
    return 0;
}
