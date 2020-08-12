// This exercise consist of ordering a stack using only another stack as auxiliary memory

#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<int>& st)
{
    stack<int> aux;
    cout << "-- stack state:\t top --> ";
    while(!st.empty())
    {
        aux.push(st.top());
        cout << st.top() << " ";
        st.pop();
    }
    while(!aux.empty())
    {
        st.push(aux.top());
        aux.pop();
    }
    cout << endl;
}

void orderStack(stack<int>& main)
{
    stack<int> aux;
    int x;
    int finished = false;
    while(!finished)
    {
        finished = true;
        x = main.top();
        main.pop();
        while(!main.empty())
        {
            if(main.top() >= x)
            {
                aux.push(x);
                x = main.top();
                main.pop();
            }
            else
            {
                finished = false;
                aux.push(main.top());
                main.pop();
            }
        }
        aux.push(x);
        while(!aux.empty())
        {
            main.push(aux.top());
            aux.pop();
        }
    }
}

int main()
{
    stack<int> main;
    cout << "-- Type list number separated by space. Type \"end\" when finished:\n";
    string s;
    cin >> s;
    while(s != "end")
    {
        main.push(stoi(s));
        cin >> s;
    }

    cout << "-- Ok. Got the following:\n";
    printStack(main);
    cout << "-- Ordering...\n";
    orderStack(main);
    cout << "-- Ordered stack: ";
    printStack(main);
    return 0;
}