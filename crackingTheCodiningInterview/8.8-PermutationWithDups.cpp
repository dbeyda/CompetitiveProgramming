#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// void mapDecr(unordered_map<char, int>& available, char key)
// {
//     --available[key];
//     if (available[key] <= 0) available.erase(key);
// }

void printPermutations(unordered_map<char, int>& available, string& currentPerm, int finalSize)
{
    if(currentPerm.size() == finalSize)
    {
        cout << currentPerm << '\n';
        return;
    }
    for(auto it = available.begin(); it != available.end(); ++it)
    {
        char key = it->first;
        int count = it->second;
        if (!count) continue;

        currentPerm.push_back(key);
        --available[key];
        printPermutations(available, currentPerm, finalSize);
        currentPerm.pop_back();
        ++available[key];
    }
}

void printPermutations(string s)
{
    unordered_map<char, int> available;
    string currentPerm;
    for(auto& c : s) ++available[c];
    printPermutations(available, currentPerm, s.size());
}

int main()
{
    string s;
    cin >> s;
    printPermutations(s);
    return 0;
}
