#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& num : nums)
        cin >> num;

    sort(nums.begin(), nums.end());
    for(int i=0; i<n-1; i++)
    {
        if (nums[i+1] - nums[i] > 1)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nCases;
    cin >> nCases;

    while(nCases--)
        solve();

    return 0;
}
