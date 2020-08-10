#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    string s, p;
    cin >> s >> p;
    vector<int> letters('z'-'a' + 1, 0);
    for(auto& c : s)
        letters[c - 'a']++;
    for(auto& c : p)
        letters[c - 'a']--;


    int pIdx = p[0] - 'a';
    bool printBefore = false;
    for(int i=0; i<p.size()-1; i++)
    {
        if (p[i] == p[i+1]) continue;
        printBefore = (p[i+1] < p[i]);
        break;
    }

    string answer = "";
    for(int i=0; i<letters.size(); i++)
    {
        if (i == pIdx && printBefore) answer.append(p);
        while(letters[i] > 0)
        {
            answer.push_back('a'+i);
            letters[i]--;
        }
        if (i == pIdx && !printBefore) answer.append(p);
    }
    cout << answer << '\n';
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
