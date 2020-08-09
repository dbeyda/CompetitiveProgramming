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
        vector<int> ans(n, 0);
        priority_queue<pair<int, int>> q;
        q.push(make_pair(n, -0));
        int it = 0;
        while(q.size())
        {
            auto top = q.top(); q.pop();
            int sz = top.first;
            int l = -top.second;
            int r = l + sz -1;
            int mid = (r + l) / 2;
            ans[mid] = ++it;
            //cout << "left: " << l << "    mid: " << mid << "      right: " << r << "     value: " << it << '\n'; 

            if(l < mid)
                q.push(make_pair(mid-l, -l));
            if(r > mid)
                q.push(make_pair(r-mid, -(mid+1)));
        }
        for(int i : ans) cout << i << " ";
        cout << '\n';
        

    }
    return 0;
}