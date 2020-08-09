#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i+=2)
        cout << s[i];
    cout << s.back();
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases;
    cin >> n_cases;

    while(n_cases--)
        solve();
    return 0;
}