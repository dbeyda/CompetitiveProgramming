#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    int n;
    cin >> n;
    list<int> firstHalf;
    list<int> secondHalf;

    firstHalf.push_back(0);
    for(int i=1; i<=sqrt(n); i++)
    {
        if (n/i == i)
        {
            firstHalf.push_back(i);
            continue;
        }
        firstHalf.push_back(i);
        secondHalf.push_front(n/i);
    }

    cout << firstHalf.size() + secondHalf.size() << '\n';
    for(auto& i : firstHalf)
        cout << i << ' ';
    for(auto& i : secondHalf)
        cout << i << ' ';
    cout << '\n';

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
