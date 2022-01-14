
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
void printMiddle(node *head)//2 Traversal of LL
{
    if(head==NULL)
    return;
    node *curr=head;
    int count=1;
    while(curr->next!=NULL)
    {
        count++;
        curr=curr->next;
    }
    curr=head;
    for(int i=0;i<count/2;i++)
    {
        curr=curr->next;
    }
    cout<<"Middle of Linked List: "<<curr->data<<" ";
}
void slowFastPointers(node *head)// 1 Traversal of LL
{
    if(head==NULL)
    return ;
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"Middle of Linked List: "<<slow->data;
}
int main()
{
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    head->next->next->next->next=new node(50);
    head->next->next->next->next->next=new node(60);
    printMiddle(head);
    cout<<endl;
    slowFastPointers(head);

    return 0;
}

