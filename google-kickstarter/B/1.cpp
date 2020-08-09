#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_tests, n, answer;
    vector<int> h; 
    cin >> n_tests;

    for(int i=0; i<n_tests; i++)
    {
        // solve each test case
        answer = 0;
        h.clear();
        cin >> n;
        for(int j=0; j<n; j++)
        {
            int el;
            cin >> el;
            h.push_back(el);
        }

        for(int j=1; j<n-1; j++)
        {
            if(h[j] > h[j-1] && h[j] > h[j+1])
                answer++;
        }
        cout << "Case #" << i+1 << ": " << answer << endl;
    }


    return 0;
}
