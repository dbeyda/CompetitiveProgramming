#include <iostream>
#include <stack>

using namespace std;

class HanoiTower
{
public:
    int id;
    stack<int> tower;

    HanoiTower(int id) : id(id) {};

    void addRing(int ring)
    {
        if (tower.size() && (tower.top() <= ring))
        {
            cout << "!! Error !! Tried to place ring " << ring << " on top of " << tower.top()
                << ". Exiting.\n";
            exit(1);
        }
        tower.push(ring);
        cout << "Placed ring " << ring << " on tower " << id << "\n";
    }

    void moveTop(HanoiTower& to)
    {
        if(tower.empty())
        {
            cout << "!! Error !! Tried to move ring from empty tower " << id
                 << ".\nExiting.\n";
            exit(1);
        }
        if (to.tower.size() && (to.tower.top() <= tower.top()))
        {
            cout << "!! Error !! Tried to place ring " << tower.top() << " (from tower " << id << ") on top of "
                 << to.tower.top() << " (from tower " << to.id << ")"
                << ". Exiting.\n";
            exit(1);
        }
        to.tower.push(tower.top());
        tower.pop();
        cout << "Moved ring " << to.tower.top() << " from tower " << id << " to tower " << to.id << ".\n";
    }
};

void solve(int n, HanoiTower& from, HanoiTower& to, HanoiTower& other)
{
    if (n <= 0) return;
    solve(n-1, from, other, to);
    from.moveTop(to);
    solve(n-1, other, to, from);
}

void solve(int n)
{
    HanoiTower t1(1), t2(2), t3(3);
    cout << "Preparing towers...\n";
    for(int i=n; i>0; --i)
        t1.addRing(i);
    cout << "\nTowers ready. Solving...\n";
    solve(n, t1, t3, t2);
    cout << "Done!\n";
}

int main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}
