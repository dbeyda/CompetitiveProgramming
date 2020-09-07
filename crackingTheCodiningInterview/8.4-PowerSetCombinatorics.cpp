#include <iostream>
#include <vector>

using namespace std;

// will work for sets of 32 elements or less

void printSubset(int x, vector<int>& v)
{
    cout << "{ ";
    const int intBits = sizeof(int)*8;
    for(int i=0; i < intBits; ++i)
    {
        int mask = 1 << i;
        if (mask & x) cout << v[i] << " ";
    }
    cout << "}\n";
}

void printSubsets(vector<int>& v)
{
    int maxInt = (1 << v.size()) -1;
    for(int i=0; i<=maxInt; ++i)
        printSubset(i, v);
}

int main()
{
    int len;
    cin >> len;
    vector<int> v(len);
    for(auto& i : v)
        cin >> i;
    printSubsets(v);
    return 0;
}
