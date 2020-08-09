#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    int n;
    cin >> n;
    list<unordered_set<char>> components;

    for(int i=0; i<n; i++)
    {
        string newWord;
        cin >> newWord;

        unordered_set<char> *parentComponent = nullptr;
        // search through all graph components
        for(auto s = components.begin(); s != components.end(); s++)
        {
            // try each letter of the world
            for(auto& letter : newWord)
            {
                if (s->count(letter))
                {
                    if (!parentComponent)
                    {
                        s->insert(newWord.begin(), newWord.end());
                        parentComponent = &(*s);
                        break;
                    }
                    else if(&(*s) != parentComponent)
                    {
                        parentComponent->insert(s->begin(), s->end());
                        auto toBeDel = s--;
                        components.erase(toBeDel);
                        break;
                    }
                }
            }
        }
        if (!parentComponent)
            components.push_back(unordered_set<char>(newWord.begin(), newWord.end()));
    }
    cout << components.size() << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nCases=1;
    //cin >> nCases;

    while(nCases--)
        solve();

    return 0;
}
