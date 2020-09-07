#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void printPermutations(vector<char>& original, string& currentPerm, unordered_set<char>& used)
{
    if(original.size() == currentPerm.size())
    {
        cout << currentPerm << '\n';
        return;
    }
    for(auto it = original.begin(); it != original.end(); ++it)
    {
        if(used.count(*it)) continue;
        currentPerm.push_back(*it);
        used.insert(*it);
        printPermutations(original, currentPerm, used);
        currentPerm.pop_back();
        used.erase(*it);
    }
}

void printPermutations(string s)
{
    vector<char> original;
    string currentPerm;
    original = vector<char>(s.begin(), s.end());
    unordered_set<char> used;
    printPermutations(original, currentPerm, used);
}

int main()
{
    string s;
    cin >> s;
    printPermutations(s);
    return 0;
}
