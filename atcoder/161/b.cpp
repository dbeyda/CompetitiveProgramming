#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> n >> m;

    int item;
    int selected = 0;
    int total_votes = 0;
    vector<int> input;

    for(int i=0; i<n; i++)
    {
        cin >> item;
        input.push_back(item);
        total_votes += item;
    }

    float baseline = (float) total_votes / (4.0f * (float) m);

    for (vector<int>::iterator i=input.begin(); i != input.end(); i++)
    {
        if ((float) *i >= baseline){
            selected++;
        }
    }

    if (selected >= m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}