#include <iostream>
#include <vector>

using namespace std;

bool isPowerOfTwo(int x)
{
    return (x != 0) && ((x & (x - 1)) == 0);
}

int recursiveMult(int x, int y)
{
    if (x < y) swap(x, y);      // set y as the smallest
    if(y == 0) return 0;
    if (y == 1) return x;
    if (y & 1 == 0)
    {
        return recursiveMult(x, y<<1) >> 1;
    }
    // if (isPowerOfTwo(x) || isPowerOfTwo(y))
    // {
    //     if(!(isPowerOfTwo(x) && isPowerOfTwo(y)) && isPowerOfTwo(x)) swap(x, y);     // set y as power of two, of both x and y are, y already is the smallest
    //     int value = recursiveMult(x, y>>1);
    //     return value + value;
    // }
    return x + recursiveMult(x, y-1);
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << recursiveMult(x, y) << endl;
    return 0;
}
