#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int mod = 1000000000;

int charToInt(char c)
{
    return c-'0';
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_tests, n, open_multiplier, total_multiplier, answer_x, answer_y;
    stack<int> mult_stack;
    cin >> n_tests;
    cin.ignore(256, '\n');
    for(int i=0; i<n_tests; i++)
    {
        // solve each test case
        int x, y;
        x = y = 0;
        total_multiplier = 1;
        open_multiplier = 0;
        mult_stack.empty();

        string s;
        getline(cin, s);

        for(int k=0; k<s.size(); k++)
        {
            if (s[k] == 'N') y -= total_multiplier;
            else if (s[k] == 'S') y += total_multiplier;
            else if (s[k] == 'W') x -= total_multiplier;
            else if (s[k] == 'E') x += total_multiplier;
            else if (isdigit(s[k]))
            {
                // read next digit of the multiplier
                open_multiplier *= 10;
                open_multiplier += charToInt(s[k]);
            }
            else if (s[k] == '(')
            {
                // close multiplier
                mult_stack.push(open_multiplier);
                total_multiplier *= open_multiplier;
                open_multiplier = 0;
                /// cout << "New Mult: " << mult_stack.top() << endl;
                // cout << "Total Mult: " << total_multiplier << endl;
            }
            else if (s[k] == ')')
            {
                // remove last multiplier effect
                total_multiplier /= mult_stack.top();
                // cout << "Removing Mult: " << mult_stack.top() << endl;
                // cout << "Total Mult: " << total_multiplier << endl;
                mult_stack.pop();
            }
        }
        answer_x = x % (mod-1);
        answer_y = y % (mod-1);
        
        if (answer_x < 0) answer_x += mod;
        if (answer_y < 0) answer_y += mod;

        // cout << "[debug] Case #" << i+1 << ": " << x+1 << " " << y+1 << endl;
        cout << "Case #" << i+1 << ": " << answer_x+1 << " " << answer_y+1 << endl;

    }
    return 0;
}
