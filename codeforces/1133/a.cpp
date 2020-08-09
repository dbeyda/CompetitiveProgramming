#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int toMinutes(int h, int m)
{
    return h*60 + m;
}

void fromMinutes(int m, int *ph, int *pm)
{
    *ph = m/60;
    *pm = m%60;
}

void printTime(int h, int m)
{
    cout << setfill('0') << setw(2) << h << ':';
    cout << setfill('0') << setw(2) << m << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nCases = 1;

    while(nCases--)
    {
        int h1, m1, h2, m2;
        scanf("%d:%d", &h1, &m1);
        scanf("%d:%d", &h2, &m2);

        int minutes1 = toMinutes(h1, m1);
        int minutes2 = toMinutes(h2, m2);
        int result = (minutes1 + minutes2) / 2;
        //cout << "To minutes result: " << result << endl;
        int resH, resM;
        fromMinutes(result, &resH, &resM);
        printTime(resH, resM);
    }

    return 0;
}
