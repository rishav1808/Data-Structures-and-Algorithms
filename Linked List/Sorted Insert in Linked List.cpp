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
void traversal(node *head)
{
    if(head==NULL)
    return;
    cout<<head->data<<" ";
    traversal(head->next);
}
node *sortedInsert(node *head,int x)
{
    node *temp=new node(x);
   if(head==NULL)
   return temp;
   if(x<head->data)
   {
       temp->next=head;
       return temp;
   }
   node *curr=head;
   while(curr->next!=NULL && curr->next->data<x)
   curr=curr->next;
   temp->next=curr->next;
   curr->next=temp;
   return head;
}
int main()
{
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    cout<<"Linked List Before: "<<" ";
    traversal(head);
    cout<<endl;
    head=sortedInsert(head,5);
    head=sortedInsert(head,35);
    head=sortedInsert(head,45);
    cout<<"Linked List After: "<<" ";
    traversal(head);
    cout<<endl;

    return 0;
}
