#include <iostream>
#include <string>
#include <vector>

using namespace std;


int coins(int n, bool quarters, bool dimes, bool nickels, bool pennies)
{
    if (n <= 0) return 1;

    int count = 0;
    if (quarters && n >= 25)
        for(int i=0; 25*i <= n; i++)
            count += coins(n - 25*i, false, true, true, true);
    else if (dimes && n >= 10)
        for(int i=0; 10*i <= n; i++)
            count += coins(n - 10*i, false, false, true, true);
    else if (nickels && n >= 5)
        for(int i=0; 5*i <= n; i++)
            count += coins(n - 5*i, false, false, false, true);
    else if (pennies && n >= 1) ++count;
    else return 0;
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << coins(n, true, true, true, true) << "\n";
    return 0;
}
