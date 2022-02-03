#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int>s;
    s.push(10);
     s.push(20);
      s.push(5);
       s.push(15);
        s.push(100);
        cout<<s.size()<<endl;
    while(s.empty()==false)//Traversal function
    {
        cout<<s.top()<<" ";
        s.pop();    }

    return 0;
}

