#include <iostream>

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
void traversal(node *head)
{
    if(head==NULL)
    return;
    cout<<head->data<<" ";
    traversal(head->next);
}
void nthFromEnd(node *head,int n)//Concept of Length of LL is used
{
    if(head==NULL)
    return ;
    node *curr=head;
    int count=1;
    while(curr->next!=NULL)
    {
        count++;
        curr=curr->next;
    }
    curr=head;
    if(count<n)
    return;
    for(int i=0;i<count-n;i++)
    curr=curr->next;
    cout<<curr->data<<" ";
}
void efficient(node *head,int n)//Concept of 2 pointers is used
{
    if(head==NULL)
    return;
    node *first=head;
    node *second=head;
    while(n--)
    {
        if(first==NULL)
        return;
        first=first->next;
    }
    
    while(first!=NULL)
    {
        first=first->next;
        second=second->next;
    }
    cout<<second->data<<" ";
}
int main()
{
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    head->next->next->next->next=new node(50);
    nthFromEnd(head,2);
    efficient(head,2);

    return 0;
}
