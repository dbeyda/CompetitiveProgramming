#include <iostream>
#include <bitset>
#include <sstream>
#include <list>

using namespace std;

template<typename T>
static std::string toBinaryString(const T& x)
{
    std::stringstream ss;
    ss << std::bitset<sizeof(T) * 8>(x) << '\n';
    return ss.str();
}

int main()
{
    double n;
    cin >> n;
    list<char> bits;
    bits.push_back('0');
    bits.push_back('.');
    while (n > 0)
    {
        if (bits.size() > 34)
        {
            cout << "Error.\n";
            return 0;
        }
        n *= 2;
        if(n >= 1)
        {
            bits.push_back('1');
            --n;
        }
        else
            bits.push_back('0');
    }

    for(auto& c : bits) cout << c;
    cout << endl;

    return 0;
}