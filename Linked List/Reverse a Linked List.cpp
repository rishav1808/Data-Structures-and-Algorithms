/* Reverse a Linked List */
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
node *reverseLinkedList(node *head)
{
    //if(head==NULL || head->next==NULL)
    //return head;
    node *dummy=NULL;
    node *curr=head;
    while(curr!=NULL)
    {
      node *next=curr->next;
      curr->next=dummy;
      dummy=curr;
      curr=next;
    }
    return dummy;
}
node *naive(node *head)
{
    vector<int>v ;
    node *curr=head;
    while(curr!=NULL)
    {
        v.push_back(curr->data);
        curr=curr->next;
    }
    curr=head;
    while(curr!=NULL)
    {
        curr->data=v.back();
        v.pop_back();
        curr=curr->next;
    }
    return head;
}
int main()
{
      node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    head->next->next->next->next=new node(50);
 
    cout<<"Linked List: "<<" ";
    traversal(head);
    cout<<endl;
    head=reverseLinkedList(head);
    //head=naive(head);
    cout<<"Reversed Linked List: "<<" ";
    traversal(head);
    

    return 0;
}
