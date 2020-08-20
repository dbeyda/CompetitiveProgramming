#include <iostream>
#include <bitset>
#include <sstream>

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
    int M = 0b1111110000000000001111111111;
    int N = 0b1100110011;

    int j = 20;
    int i = 11;

    int result = 0;

    int left = -1 << (j+1);
    int right = ~(-1 << i);
    int mask = left | right;
    result = (M & mask) | (N<<i);

    std::cout << toBinaryString(result);
    return 0;
}