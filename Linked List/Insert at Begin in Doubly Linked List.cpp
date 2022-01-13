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
node *insertBegin(node *head,int value)
{
    
    node *temp=new node(value);
    if(head==NULL)
    return temp;
    else{
        temp->next=head;
        head->prev=temp;
        return temp;
    }
    
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
    head=insertBegin(head,5);
    cout<<"Linked List After: ";
    traversal(head);

    return 0;
}
