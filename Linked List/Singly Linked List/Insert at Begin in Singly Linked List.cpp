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
node *insertBegin(node *head,int x)
{
    node *newHead=new node(x);
    newHead->next=head;
    return newHead;
    
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
    head->next=new node(20);
    head->next->next=new node(30);
    cout<<"Linked List Before: "<<" ";
    traversal(head);
    cout<<endl;
    
    head=insertBegin(head,999);
    cout<<"Linked List After: "<<" ";
    traversal(head);

    return 0;
}

