#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Point
{
    public:
    int x, y;
    bool blocked;
    Point(int x, int y, bool blocked) : x(x), y(y), blocked(blocked) {}
};

class Grid
{
    public:
    int rows, cols;
    vector<vector<Point*>> grid;
    Grid(vector<vector<Point*>>& grid) : grid(grid)
    {
        rows = grid.size();
        cols = grid[0].size();
    }
    Point* right(Point* p)
    {
        if (p->x >= cols-1) return nullptr;
        return grid[p->y][p->x+1];
    }
    Point* down(Point *p)
    {
        if (p->y >= rows-1) return nullptr;
        return grid[p->y+1][p->x];
    }
};


bool getPath(Grid& grid, vector<Point*>& currentSol, unordered_set<Point*>& badCells, Point* start, Point* end);

vector<Point*> getPath(Grid& grid)
{
    vector<Point*> currentSol;
    unordered_set<Point*> badCells;
    getPath(grid, currentSol, badCells, grid.grid[0][0], grid.grid[grid.cols-1][grid.rows-1]);
    return currentSol;
}

bool getPath(Grid& grid, vector<Point*>& currentSol, unordered_set<Point*>& badCells, Point* start, Point* end)
{
    if(start->blocked || badCells.count(start)) return false;

    currentSol.push_back(start);
    if(start == end) return true;

    Point* right = grid.right(start);
    if (right && getPath(grid, currentSol, badCells, right, end))
        return true;

    Point* down = grid.down(start);
    if (down && getPath(grid, currentSol, badCells, down, end))
        return true;

    currentSol.pop_back();
    badCells.insert(start);
    return false;
}

int main()
{
    int xLen, yLen;
    cin >> xLen >> yLen;
    if (!xLen || !yLen)
    {
        cout << "No path possible.\n";
        return 0;
    }
    vector<vector<Point*>> grid(yLen, vector<Point*>(xLen, 0));
    for(int row = 0; row < yLen; row++)
        for(int col = 0; col < xLen; col++)
        {
            int blocked; cin >> blocked;
            grid[row][col] = new Point(col, row, blocked);
        }

    Grid g(grid);
    vector<Point*> path = getPath(g);
    if (path.size() == 0) cout << "No path found.\n";
    else for(auto& p : path)
        cout << "(" << p->x << ", " << p->y << ")\n";
    return 0;
}
