#include <iostream>

using namespace std;

int maxSeq(int n)
{
    int maxSeq = 1;
    int prevSeq = 0;
    int currentSeq = 0;
    for(int i=0; i<sizeof(n)*8; ++i)
    {
        if ((n & 1) == 1)
        {
            ++currentSeq;
            maxSeq = max(maxSeq, prevSeq + 1 + currentSeq);
        }
        else
        {
            prevSeq = currentSeq;
            currentSeq = 0;
        }
        n = n >> 1;
    }
    return maxSeq;
}

int main()
{
    int n;
    n = 0b1111100111111010;
    cout << maxSeq(n) << endl;


    return 0;
}