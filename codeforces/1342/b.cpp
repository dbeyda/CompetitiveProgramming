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
        string s;
        cin >> s;
        if (s.size() <= 2)
        {
            cout << s << endl;
            continue;
        }
        // if string is composed of only one char, return the same string
        char first = s[0];
        bool onlyOneChar = true;
        for( auto& i : s)
        {
            if (i != first)
            {
                onlyOneChar = false;
                break;
            }
        }
        if (onlyOneChar)
        {
            cout << s << endl;
            continue;
        }
        // iterate over string and make 010101010 or 10101010
        for(int i=0; i< s.size(); i++)
        {
            cout << s[i];
            if (i < s.size()-1 && (s[i] == s[i+1]))
            {
                if (s[i] == '0')
                    cout << "1";
                else
                    cout << "0";
            }
        }
        cout << endl;
    }
    return 0;
}
