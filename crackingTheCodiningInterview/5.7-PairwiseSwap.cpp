#include <iostream>
#include <bitset>
#include <sstream>
#include <iomanip>

using namespace std;

template<typename T>
static std::string toBinaryString(const T& x)
{
    std::stringstream ss;
    ss << std::bitset<sizeof(T) * 8>(x) << '\n';
    return ss.str();
}

using namespace std;


int swapped(int n)
{
    return ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
}

int main()
{
    int n = 0b100110010111;
    cout << toBinaryString(n) << toBinaryString(swapped(n));
    return 0;
}
