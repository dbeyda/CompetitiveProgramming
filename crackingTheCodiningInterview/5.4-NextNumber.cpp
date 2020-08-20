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

int smaller(int n)
{
    int i = 1;
    int c1 = 0;
    int c0 = 0;
    // eat trailing 1s
    while((n & 1) == 1)
    {
        c1++;
        n = n >> 1;
    }
    if (n == 0) return -1;
    // eat first 0s
    while((n & 1) == 0 && n != 0)
    {
        c0++;
        n = n >> 1;
    }

    --n;
    n = n << (c0 + c1);
    // add c1-1 1s
    int ones = 1 << (c1+1);
    --ones;
    ones = ones << (c0-1);
    int result = n | ones;
    return result;
}

int bigger(int n)
{
    int i = 1;
    int c1 = 0;
    int c0 = 0;
    // eat trailing zeros
    while((n & 1) == 0 && n != 0)
    {
        c0++;
        n = n >> 1;
    }
    // eat first 1s
    while((n & 1) == 1)
    {
        c1++;
        n = n >> 1;
    }
    if ((c0 + c1 > 32) || (c0 + c1 == 0))
        return -1;

    n += 1;
    n = n << (c0 + c1);
    // add c1-1 1s
    int ones = 1 << (c1-1);
    --ones;
    int result = n | ones;
    return result;
}

int main()
{
    int n;
    n = 0b011111;
    cout << setw(14) << "base number: "  << setw(6) << n << " - " << toBinaryString(n);
    cout << setw(14) << "smaller: " << setw(6) << smaller(n) << " - " << toBinaryString(smaller(n));
    cout << setw(14) << "larger: " <<  setw(6) << bigger(n) << " - " << toBinaryString(bigger(n));
    return 0;
}