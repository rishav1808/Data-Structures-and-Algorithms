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
bool detectLoop(node *head)
{
    unordered_set<node *>s;
    node *curr=head;
    while(curr->next!=NULL)
    {
        if(s.find(curr)!=s.end())
        {
            s.insert(curr);
            curr=curr->next;
        }
        else
        return true;
    }
    return false;
}
bool floydCycle(node *head)
{
    if(head==NULL || head->next==NULL)//List is empty or only 1 item that too points to Null
    return false;
    node *curr=head,*slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL)//We move fast 2 times so it is possible that
    {                               //If fast->next==NULL then fast->next->next will give excpetion
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        return true;
    }
    return false;
}
int main()
{
    node *head=new node(15);
	head->next=new node(10);
	head->next->next=new node(12);
	head->next->next->next=new node(20);
	head->next->next->next->next=head->next;
	if (floydCycle(head)) 
        cout << "Loop found"; 
    else
        cout << "No Loop"; 
    cout<<endl;    
    if (detectLoop(head)) 
        cout << "Loop found"; 
    else
        cout << "No Loop"; 
	return 0;

    
}

