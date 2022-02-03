#include <bits/stdc++.h>

using namespace std;

struct Stack{
    int *arr;
    int capacity;
    int top;
    Stack(int x)
    {
        arr=new int[x];
        capacity=x;
        top=-1;
    }
    void push(int x)
    {
        if(top==capacity-1)
        {
            cout<<"Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    int pop()
    {
        if(top==-1)
        {
            cout<<"Empty Stack"<<endl;
            return INT_MIN;
        }
        int res=arr[top];
        top--;
        return res;
    }
    int peek()
    {
        if(top==-1)
        {
             cout<<"Empty Stack"<<endl;
            return INT_MIN;
        }
        return(arr[top]);
    }
    int size()
    {
        return(top+1);
    }
    bool empty()
    {
        if(top==-1)
        return true;
        return false;
    }
    void print()
    {
        for(int i=0;i<=top;i++)
        cout<<arr[i]<<" ";
    }
    
};

int main()
{
    Stack s(5);
     s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.empty()<<endl;
    s.print();
    
    

    return 0;
}
