#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

void generate(string &currWord, map<char, int> &left, int n, vector<string> &words)
{
    if(currWord.size() == n)
        words.push_back(currWord);
    else
    {
        for(auto it = left.begin(); it != left.end(); ++it)
        {
            if (it->second == 0) continue;
            currWord.push_back(it->first);
            it->second--;
            generate(currWord, left, n, words);
            it->second++;
            currWord.pop_back();
        }
    }
}

void solve()
{
    string s; cin >> s;
    sort(s.begin(), s.end());
    map<char, int> left;
    for(auto& c : s) left[c]++;
    vector<string> words;
    string currWord = "";
    
    generate(currWord, left, s.size(), words);
    
    cout << words.size() << endl;
    for(auto& w : words) cout << w << '\n'; 
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w+", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long t=1;
    // cin >> t;
    for(int it=1; it<=t; it++)
        solve();
    return 0;
}