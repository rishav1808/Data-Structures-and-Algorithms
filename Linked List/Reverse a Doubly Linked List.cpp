#include <iostream>

using namespace std;
struct node{
    int data;
    node *prev;
    node *next;
    node(int x)
    {
        data=x;
        prev=NULL;
        next=NULL;
    }
};

node *reverseDLL(node *head)
{
    if(head==NULL || head->next==NULL)
    return head;
    node *curr=head;
    node *prev=NULL;
    while(curr!=NULL)
    {
        prev=curr->prev;
        curr->prev=curr->next;
        curr->next=prev;
        curr=curr->prev;
    }
    return prev->prev;
}
void traversal(node *head)
{
    if(head==NULL)
    return;
    cout<<head->data<<" ";
    traversal(head->next);
}
int main()
{
    node *head=new node(10);
    node *temp1=new node(20);
    node *temp2=new node (30);
    head->next=temp1;
    temp1->prev=head;
    temp1->next=temp2;
    temp2->prev=temp1;
    cout<<"Linked List Before: ";
    traversal(head);
    cout<<endl;
    head=reverseDLL(head);
    cout<<"Linked List After: ";
    traversal(head);

    return 0;
}
