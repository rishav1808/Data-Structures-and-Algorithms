/* Deletion of First Node in Singly Linked List */
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
node *deletionFirst(node *head)
{
    if(head==NULL)
    return NULL;
    node *temp=head->next;
    head->next=NULL;
    return temp;
}
void traversal(node *head)
{
    if(head==NULL)
    return;
    cout<<head->data<<" ";
    traversal(head->next);
}

int main()
{    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    cout<<"Linked List Before: "<<" ";
    traversal(head);
    cout<<endl;
    head=deletionFirst(head);
    cout<<"Linked List After: "<<" ";
    traversal(head);
     head=deletionFirst(head);
    cout<<"Linked List After: "<<" ";
    traversal(head);
     head=deletionFirst(head);
    cout<<"Linked List After: "<<" ";
    traversal(head);
    
