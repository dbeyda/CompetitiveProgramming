#include <iostream>
#include <bitset>
#include <sstream>
#include <vector>

using namespace std;

template<typename T>
static std::string toBinaryString(const T& x)
{
    std::stringstream ss;
    ss << std::bitset<sizeof(T) * 8>(x);
    return ss.str();
}

using namespace std;


void drawLine(vector<char>& v, int width, int x1, int x2, int y)
{
    width /= 8;
    int height = v.size() / width;
    int startIdx = width * y + x1/8;
    int startBit = x1 % 8;
    ++x2;
    int endIdx = width * y + x2/8;
    int endBit = x2 % 8;

    v[startIdx] = (1 << (8 - startBit)) -1;
    if (startIdx == endIdx)
        v[endIdx] &= ~((1 << (8 - endBit)) -1);
    else
        v[endIdx] = ~((1 << (8 - endBit)) -1);
    for(int i=startIdx+1; i < endIdx; i++)
        v[i] = 0xff;
}

void printScreen(vector<char>& v, int width)
{
    width /= 8;
    for(int i=0; i < v.size(); i++)
    {
        if((i) % width == 0) cout << '|';
        cout << toBinaryString(v[i]) << "|";
        if((i+1) % width == 0)
            cout << '\n';
    }
    cout << endl;
}

int main()
{
    int n = 16;
    vector<char> screen(n, 0);
    int width = 32;
    int x1 = 6;
    int x2 = 26;
    int y = 3;
    drawLine(screen, width, x1, x2, y);
    printScreen(screen, width);
    return 0;
}
