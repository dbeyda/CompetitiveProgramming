#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases, n, x;
    cin >> n_cases;

    while(n_cases--)
    {
        // solve one test case
        cin >> n;
        map<int, int> s_count;
        for(int i=0; i<n; i++)
        {
            cin >> x;
            s_count[x]++;
        }

        int dif_elements = s_count.size();
        int max_repeated = 0;
        for(map<int, int>::iterator i=s_count.begin(); i != s_count.end(); i++)
        {
            if (i->second > s_count[max_repeated])
                max_repeated = i->first;
        }

        int answer;
        if ((dif_elements-1) >= s_count[max_repeated])
            answer = s_count[max_repeated];
        else
            answer = min(dif_elements, s_count[max_repeated]-1);
        cout << answer << '\n';
    }
    return 0;
}