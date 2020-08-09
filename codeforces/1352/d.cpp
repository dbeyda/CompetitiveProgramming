#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int eat(bool aliceTurn, list<int>& a)
{
    int v;
    if (aliceTurn)
    {
        v = a.front();
        a.pop_front();
    }
    else {
        v = a.back();
        a.pop_back();
    }
    return v;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases;
    cin >> n_cases;

    while(n_cases--)
    {
        int n;
        cin >> n;
        list<int> a;
        for(int i=0; i<n; i++)
        {
            int ai;
            cin >> ai;
            a.push_back(ai);
        }
        int aSum = 0, bSum = 0;
        int lastEatenSum = 0;
        bool aliceTurn = true;
        int moves = 0;
        while(a.size())
        {
            moves++;
            int turnEat = 0;
            while(a.size() && (turnEat <= lastEatenSum))
            {
                turnEat += eat(aliceTurn, a);
            }
            if (aliceTurn)
                aSum += turnEat;
            else
                bSum += turnEat;
            lastEatenSum = turnEat;
            aliceTurn = !aliceTurn;
        }

        cout << moves << " " << aSum << " " << bSum << "\n";
    }
    return 0;
}