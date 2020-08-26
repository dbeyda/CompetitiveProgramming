#include <iostream>
#include <vector>

using namespace std;

template <class T>
class CircularArray
{
    vector<T> v;
    int front;

public:
    CircularArray() { front = 0; }

    int size() { return v.size(); }

    void push_back(T newElement) { v.push_back(newElement); }

    void pop_back() { if (v.size()) v.pop_back(); }

    T get(int pos) { return v[(front + pos) % v.size()]; }

    void operator>> (int shift)
    {
        int mod = v.size();
        front = (front % mod - shift % mod) % mod;
        if (front < 0) front += v.size();
    }
    void operator<< (int shift)
    {
        int mod = v.size();
        front = (front % mod + shift % mod ) % mod;
    }

    class simpleIterator {
    public:
        simpleIterator(int idx, vector<T> *v): idx(idx), v(v), steps(0) {}
        simpleIterator operator++()
        {
            ++idx;
            idx = idx % v->size();
            ++steps;
            return *this;
        }
        bool operator!=(const simpleIterator & other) const
        {
            return idx != other.idx || steps == other.steps;
        }
        const T& operator*() const { return v->at(idx); }
    private:
        int idx;
        vector<T> *v;
        int steps;
   };

   simpleIterator begin() { return simpleIterator(front, &v); }
   simpleIterator end() { return begin(); }
};

int main()
{
    CircularArray<int> ca;
    cout << "--Single element testing...\n";
    cout << "size: " << ca.size() << '\n';
    ca.push_back(0);
    cout << "pushed 0.\n";
    cout << "size: " << ca.size() << '\n';
    cout << "> get(0): " << ca.get(0) << '\n';
    cout << "shifting >> 2\n";
    ca >> 2;
    cout << "> get(-1): " << ca.get(-1) << '\n';

    cout << "\n--Multiple element testing...\n";
    cout << "Pushing 1, 2, 3, 4, 5, 6, 7.\n";
    ca.push_back(1);
    ca.push_back(2);
    ca.push_back(3);
    ca.push_back(4);
    ca.push_back(5);
    ca.push_back(6);
    ca.push_back(7);
    cout << "size: " << ca.size() << '\n';
    cout << "> get(1): " << ca.get(1) << '\n';
    cout << "> get(6): " << ca.get(6) << '\n';
    cout << "> get(-1): " << ca.get(-1) << '\n';
    cout << "shifting >> 2.\n";
    ca >> 2;
    cout << "> get(0): " << ca.get(0) << '\n';
    cout << "shifting << 2.\n";
    ca << 2;
    cout << "> get(0): " << ca.get(0) << '\n';

    cout << "\n--Printing test:\n";
    for(auto a : ca)
        cout << a << " ";
    cout << '\n';
    cout << "shifting << 3.\n";
    ca << 3;
    for(auto a : ca)
        cout << a << " ";
    cout << '\n';


    return 0;
}
