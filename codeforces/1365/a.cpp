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
        int nrows, ncols;
        cin >> nrows >> ncols;
        vector<bool> freeCols(ncols, true);
        vector<bool> freeRows(nrows, true);

        for(int i=0; i<nrows; i++)
            for(int j=0; j<ncols; j++)
            {
                int el;
                cin >> el;
                if (el)
                {
                    freeRows[i] = false;
                    freeCols[j] = false;
                }
            }
        
        int sumFreeCols=0, sumFreeRows=0;
        for(int i=0; i<freeCols.size(); i++)
            if(freeCols[i]) sumFreeCols++;
        for(int i=0; i<freeRows.size(); i++)
            if(freeRows[i]) sumFreeRows++;
        
        int minFree = min(sumFreeCols, sumFreeRows);
        if (minFree % 2)
            cout << "Ashish\n";
        else
            cout << "Vivek\n";
    }
    return 0;
}