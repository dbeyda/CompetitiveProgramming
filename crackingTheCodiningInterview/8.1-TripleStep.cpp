#include <iostream>
#include <vector>

using namespace std;

int countWaysBasic(int x)
{
    if (x < 0) return 0;
    if (x == 0) return 1;
    return countWaysBasic(x-1) + countWaysBasic(x-2) + countWaysBasic(x-3);
}

int countWaysMemo(int x)
{
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<x+1; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
        if (i-3 >=0) dp[i] += dp[i-3];
    }
    return dp[x];
}

int countWaysBetter(int x)
{
    int a, b, c, count;
    a = 0;
    b = c = 1;
    count = 0;
    for(int i=2; i<x+1; i++)
    {
        count = a + b + c;
        a = b;
        b = c;
        c = count;
    }
    return count;
}


int main()
{
    int x;
    cin >> x;
    cout << countWaysBasic(x) << endl;
    return 0;
}
