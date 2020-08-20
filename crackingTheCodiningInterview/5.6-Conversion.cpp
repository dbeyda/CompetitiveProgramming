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


int convert(int a, int b)
{
    a = a ^ b;
    int ones = 0;
    for(int i=0; i<sizeof(int) * 8; ++i)
    {
        ones += a & 1;
        a = a >> 1;
    }
    return ones;
}

int main()
{
    int a = 0b111000;
    int b = 0b011011;
    int n = convert(a, b);
    cout << "You need to flip " << n << " bits to convert\n" << toBinaryString(a) << "into\n" << toBinaryString(b);
    return 0;
}
