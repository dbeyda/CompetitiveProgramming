#include <iostream>
#include <string>
#include <vector>

using namespace std;


void parens(vector<string>& p, int n)
{
    if (n == 0) return;
    else if (n == 1) p.push_back("()");
    else
    {
        parens(p, n-1);
        int pSize = p.size();
        for(int i=0; i<pSize; ++i)
        {
            p.push_back("(" + p[i] + ")");
            p[i] = "()" + p[i];
            if (i) p.push_back(p[i] + "()");
        }
    }
}

void parens(int n)
{
    vector<string> p;
    parens(p, n);
    for(auto& s : p) cout << s << "\n";
}

int main()
{
    int n;
    cin >> n;
    parens(n);
    return 0;
}
