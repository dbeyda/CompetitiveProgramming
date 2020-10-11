#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);


void solve()
{
    int n, squareSize;
    int firstRow[2];
    int secondRow[2];
    cin >> n >> squareSize;
    bool answer = false;
    int tylesLeft = n;
    while(tylesLeft--)
    {
        cin >> firstRow[0] >> firstRow[1];
        //cout << "read first row " << firstRow[0] << firstRow[1] << '\n';
        cin >> secondRow[0] >> secondRow[1];
        if(secondRow[0] == firstRow[1])
            answer = true;
    }

    if (answer && (squareSize % 2 == 0)) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases = 1;
    cin >> n_cases;

    while(n_cases--) solve();
    return 0;
}