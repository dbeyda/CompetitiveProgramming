#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool toBool(char c)
{
    return (c == '1');
}

bool eval(char first, char op, char second)
{
    bool firstVal = toBool(first);
    bool secondVal = toBool(second);
    if (op == '^') return firstVal ^ secondVal;
    else if (op == '&') return firstVal & secondVal;
    else if (op == '|') return firstVal | secondVal;
    return false;
}

int ways(vector<vector<vector<int>>>& memo, string& s, int start, int end, bool result)
{
    if (memo[start][end][result] != -1) return memo[start][end][result];
    if (start == end)
        return toBool(s[start]) == result;

    else if (start + 2 == end)
        return eval(s[start], s[start+1], s[end]) == result;

    // x | (xxxxxxxx)
    int count = 0;
    if (eval(s[start], s[start+1], '1') == result)
        count += ways(memo, s, start+2, end, true);
    if (eval(s[start], s[start+1], '0') == result)
        count += ways(memo, s, start+2, end, false);

    // (xxxxxxxx) | x
    if (eval('1', s[end-1], s[end]) == result)
        count += ways(memo, s, start, end-2, true);
    if (eval('0', s[end-1], s[end]) == result)
        count += ways(memo, s, start, end-2, false);

    // (xxxxx) | (xxxxx)
    if((end - start >= 6) && ((end - start + 1) % 2))
    {
        int mid = (start+end)/2;
        char op = s[mid];
        if (eval('0', op, '0') == result)
            count += ways(memo, s, start, mid-1, false) * ways(memo, s, mid+1, end, false);
        if (eval('0', op, '1') == result)
            count += ways(memo, s, start, mid-1, false) * ways(memo, s, mid+1, end, true);
        if (eval('1', op, '0') == result)
            count += ways(memo, s, start, mid-1, true) * ways(memo, s, mid+1, end, false);
        if (eval('1', op, '1') == result)
            count += ways(memo, s, start, mid-1, true) * ways(memo, s, mid+1, end, true);
    }
    memo[start][end][result] = count;
    return count;
}

int ways(string s, bool result)
{
    vector<vector<vector<int>>> memo(s.size(), vector<vector<int>>(s.size(), vector<int>(2, -1)));
    return ways(memo, s, 0, s.size()-1, result);
}

int main()
{
    string expression = "0&0&0&1^1|0";
    cout << ways(expression, true) << '\n';
    return 0;
}
