#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <string>
#include <unistd.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
long long modulo = 998244353ll; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, element;
    vector<int> v;
    vector<int> ordered;

    cin >> n >> k;

    for(int i=0; i<n; i++)
    {
        cin >> element;
        v.push_back(element);
    }

    // finding max value and put k biggest elements in a set
    long long max_value = 0ll;

    ordered = v;
    sort(ordered.rbegin(), ordered.rend());

    set<int> k_set;
    for (vector<int>::iterator it=ordered.begin(); it < ordered.begin()+k; it++)
    {
        k_set.insert(*it);
        max_value += (long long) *it;
    }

    // find combinations
    long long mult = 1ll;
    long long steps = 0ll;
    bool found_first = false;
    
    for (vector<int>::iterator it=v.begin(); it != v.end(); it++) 
    {
        // find first in set
        if (!found_first && !k_set.count(*it))
        {
            continue;
        }
        
        if (k_set.count(*it)) {
            found_first = true;
            if (steps)
                mult = (mult * (steps % modulo)) % modulo;
            steps = 0ll;
        }
        steps++;
    }

    cout << max_value << " " << mult << '\n';

    return 0;
}
