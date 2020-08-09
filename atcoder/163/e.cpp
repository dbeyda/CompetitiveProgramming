#include <iostream>
#include <bits/stdc++.h>
#define ll long long


using namespace std;

struct my_comparator
{
    // queue elements are vectors so we need to compare those
    bool operator()(std::vector<int>* const& a, std::vector<int>* const& b) const
    {
        // sanity checks
        assert(a->size() == 2);
        assert(b->size() == 2);

        // reverse sort puts the lowest value at the top    
        return (*a)[1] > (*b)[1];
    }
};


using mpq = std::priority_queue<std::vector<int>*, std::vector<std::vector<int>*>, my_comparator>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mpq q;
    vector<int> a;
    vector<int> id;    // position -> child id
    vector<int> pos;           // child id -> position
    map<int, int> m_happiness;   // child_id -> happiness
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int activeness;
        cin >> activeness;
        id.push_back(i);
        a.push_back(activeness);
        q.push(new vector<int>({i, activeness}));
        m_happiness[i] = 0;
    }

    pos = id;
    int happiness = 0;
    for(int i=0; i<n; i++)
    {
        vector<int> *child = q.top();
        q.pop();
        int biggest_delta=0;
        int biggest_delta_idx=i;
        int child_id = (*child)[0];
        int child_pos = pos[child_id];
        for(int j=0; j<n; j++)
        {
            int other_id = id[j];

            if (child_id == other_id) continue;
            int delta = (0 - m_happiness[child_id] - m_happiness[other_id]);
            delta += a[child_id]*abs(j - child_id) + a[other_id]*abs(pos[child_id] - other_id);
            if (delta > 0)
            {
                happiness += delta;
                m_happiness[child_id] = a[child_id]*abs(j - child_id);
                m_happiness[other_id] = a[other_id]*abs(pos[child_id] - other_id);

                // swap
                id[j] = child_id;
                id[child_pos] = other_id;
                // swap
                pos[other_id] = pos[child_id];
                pos[child_id] = j;
            }
        }
        delete(child);
    }
    cout << happiness << '\n';
    return 0;
}