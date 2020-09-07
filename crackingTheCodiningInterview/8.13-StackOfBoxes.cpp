#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Box
{
    public:
    int d1, d2, height, area;
    Box(int _d1, int _d2, int _height) : d1(_d1), d2(_d2), height(_height)
    {
        area = d1 * d2;
    }
    bool isCompat(Box& current)
    {
        if (d1 <= current.d1) return false;
        if (d2 <= current.d2) return false;
        return true;
    }
};


int calculateHighestTower(vector<Box>& boxes, vector<int>& memo, int baseIdx)
{
    if (baseIdx >= boxes.size()-1) return 0;
    if (memo[baseIdx]) return memo[baseIdx];

    int highest = 0;
    for(int i=baseIdx+1; i<boxes.size(); ++i)
    {
        Box& newBox = boxes[baseIdx];
        if(boxes[i].isCompat(newBox))
        {
            int newHeight = boxes[i].height;
            newHeight += calculateHighestTower(boxes, memo, i);
            highest = max(newHeight, highest);
        }
    }
    memo[baseIdx] = highest;
    return highest;
}


int highestTower(vector<Box>& boxes)
{
    sort(boxes.begin(), boxes.end(),
        [](const Box& b1, const Box& b2)
        { return b1.area < b2.area; });

    int highest = 0;
    vector<int> memo(boxes.size(), 0);

    for(int i=0; i<boxes.size(); ++i)
        highest = max(highest, boxes[i].height + calculateHighestTower(boxes, memo, i));
    return highest;
}

int main()
{
    vector<Box> box = {
        {2, 2, 3},
        {3, 4, 1},
        {1, 1, 6},
        {5, 2, 5},
        {6, 5, 3},
        {10, 8, 2},
        {10, 8, 1},
        {11, 15, 3}
    };
    cout << highestTower(box) << '\n';
    return 0;
}
