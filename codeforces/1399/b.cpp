#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    long long n;
    cin >> n;

    long long minA = 1e9 + 7;
    long long minB = 1e9 + 7;
    vector<long long> a(n);
    vector<long long> b(n);

    for(auto& num : a)
    {
        cin >> num;
        if (num < minA) minA = num;
    }
    for(auto& num : b)
    {
        cin >> num;
        if (num < minB) minB = num;
    }

    long long totalMoves = 0;
    long long moves = 0;
    for(long long i=0; i<n; i++)
    {
        long long deltaA = a[i] - minA;
        long long deltaB = b[i] - minB;
        // try to eat from both
        moves = min(deltaA, deltaB);
        totalMoves += moves;
        // eat the rest
        deltaA -= moves;
        deltaB -= moves;
        totalMoves += (deltaA + deltaB);

    }
    cout << totalMoves << "\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long nCases;
    cin >> nCases;

    while(nCases--)
        solve();

    return 0;
}
