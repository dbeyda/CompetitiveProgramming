#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

template <typename T>
class MyQueue
{
private:
    stack<T> addStack;
    stack<T> reverseStack;

    void transferAll()
    {
        while(!addStack.empty())
        {
            cout << "-- transfering " << addStack.top() << endl;
            reverseStack.push(addStack.top());
            addStack.pop();
        }
    }

public:
    T front()
    {
        return reverseStack.top();
    }
    void pop()
    {
        if(reverseStack.empty()) return;
        reverseStack.pop();
        if(reverseStack.empty()) transferAll();
    }
    void push(T a)
    {
        if(reverseStack.empty() && addStack.empty()) reverseStack.push(a);
        else addStack.push(a);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue<int> answer;
    MyQueue<int> test;

    test.push(1);
    answer.push(1);
    cout << "Queue front: " << answer.front() << ". My front: " << test.front() << '\n';
    test.push(4);
    answer.push(4);
    cout << "Queue front: " << answer.front() << ". My front: " << test.front() << '\n';
    test.push(15);
    answer.push(15);
    cout << "Queue front: " << answer.front() << ". My front: " << test.front() << '\n';
    test.pop();
    answer.pop();
    cout << "Queue front: " << answer.front() << ". My front: " << test.front() << '\n';
    test.push(15);
    answer.push(15);
    cout << "Queue front: " << answer.front() << ". My front: " << test.front() << '\n';
    test.push(25);
    answer.push(25);
    cout << "Queue front: " << answer.front() << ". My front: " << test.front() << '\n';
    test.pop();
    answer.pop();
    cout << "Queue front: " << answer.front() << ". My front: " << test.front() << '\n';
    test.pop();
    answer.pop();
    cout << "Queue front: " << answer.front() << ". My front: " << test.front() << '\n';
    test.pop();
    answer.pop();
    cout << "Queue front: " << answer.front() << ". My front: " << test.front() << '\n';

    return 0;
}
