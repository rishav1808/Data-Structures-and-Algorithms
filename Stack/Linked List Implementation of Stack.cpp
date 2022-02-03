#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};

struct Stack{
    node *head;
    int size;
    Stack()
    {
        head=NULL;
        size=0;
    }
    
    void push(int x)
    {
        node *temp=new node(x);
        temp->next=head;
        head=temp;
        size++;
    }
    int pop()
    {
        if(head==NULL)
        return INT_MAX;
        int res=head->data;
        node *temp=head;
        head=head->next;
        delete(temp);
        size--;
        return res;
        
    }
    int peek()
    {
        if(head==NULL)
        return INT_MAX;
        return head->data;
    }
    int Size()
    {
        return size;
    }
    bool empty()
    {
        if(head==NULL)
        return true;
        return false;
        
    }
    void print()
    {
        node *temp=head;
        while(temp!=NULL)
        {
            if(temp!=NULL)
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    s.pop();
    s.pop();
   
    cout<<endl;
    s.print();

    return 0;
}

