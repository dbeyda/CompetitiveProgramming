#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int sum=0;

    for(int i=0; i<m; i++)
    {
        int days;
        cin >> days;
        sum += days;
    }

    int days_left = n - sum;
    if (days_left >= 0)
        cout << days_left << endl;
    else
        cout << -1 << endl;
    return 0;
}