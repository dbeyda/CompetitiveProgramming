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
        return (*a)[1] < (*b)[1];
    }
};


using mpq = std::priority_queue<std::vector<int>*, std::vector<std::vector<int>*>, my_comparator>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mpq q;
    vector<int> a;
    vector<int> pos;       // child id -> position
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int activeness;
        cin >> activeness;
        pos.push_back(i);
        a.push_back(activeness);
        q.push(new vector<int>({i, activeness}));
    }
    cout << "ate aqui foi" << endl;
    vector<int> fixed(n, 0);

    for(int i=0; i<n; i++)
    {
        vector<int> *child = q.top();
        q.pop();
        int child_id = (*child)[0];
        int final_pos = pos[child_id];
        cout << "ate aqui foi" << endl;
        for(int j=0; j<n; j++)
        {
            if ((abs(j-pos[child_id]) > final_pos) && fixed[j]==0)
                final_pos = j;
        }
        cout << "Final pos=" << final_pos << endl;
        cout << "ate aqui foi" << endl;
        fixed[final_pos] = 1;
        cout << "fixed atualizado" << endl;
        pos[child_id] = final_pos;
        cout << "pos atualizado" << endl;
        delete(child);
    }
    
    cout << "ate aqui foi" << endl << endl;

    int happiness = 0;
    for(int i=0; i<n; i++)
    {
        happiness += a[i] * abs(i - pos[i]);
    }
    cout << "ate aqui foi" << endl  << endl;


    cout << happiness << '\n';
    return 0;
}