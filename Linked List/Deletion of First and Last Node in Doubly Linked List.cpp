

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

node *deleteHead(node *head)
{
    if(head==NULL || head->next==NULL)
    return NULL;
    head->next->prev=NULL;
    head=head->next;
    return head;
}
node *deleteTail(node *head)
{
    if(head==NULL)
    return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    node *curr=head;
    while(curr->next!=NULL)
    curr=curr->next;
    curr->prev->next=NULL;
    delete curr;
    return head;
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
    head=deleteHead(head);
    cout<<"Linked List After Deleting Head: ";
    traversal(head);
    cout<<endl;
    head=deleteTail(head);
    cout<<"Linked List After Deleting Tail: ";
    traversal(head);
    

    return 0;
}
