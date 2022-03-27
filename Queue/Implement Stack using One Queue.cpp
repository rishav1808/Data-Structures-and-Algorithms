#include <bits/stdc++.h>

using namespace std;
class Stack_Queue{
    queue<int>q;
    
    void push(int x)
    {
        q.push(x);
        for(int i=0;i<q.size()-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop()
    {
        int x=q.front();
        q.pop();
        return x;
    }
}
int main()
{
    Stack_Queue s= new Stack_Queue;

    return 0;
}

