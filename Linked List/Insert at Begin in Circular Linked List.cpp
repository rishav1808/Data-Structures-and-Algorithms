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
node *insertBegin(node *head,int value)
{
    node *temp=new node(value);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    temp->next=head;
    node *curr=head;
    while(curr->next!=head)
    curr=curr->next;
    curr->next=temp;
    return temp;
}
node *efficient(node *head,int value)
{
    node *temp=new node(value);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else{
        temp->next=head->next;
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        return head;
    }
}
node * insertEnd(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else{
        node *curr=head;
        while(curr->next!=head)
        curr=curr->next;
        curr->next=temp;
        temp->next=head;
        return head;
        }
}
void traversal(node *head)
{
    node *curr=head;
    cout<<curr->data<<" ";
    while(curr->next!=head)
    {
        curr=curr->next;
         cout<<curr->data<<" ";
         
    }
   
}
int main()
{
    node *head=new node(10);
   head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    head->next->next->next->next=head;
    cout<<"Linked List Before Insetion: "<<" ";
    traversal(head);
    cout<<endl;
    head=insertBegin(head,50);
    cout<<"Linked List After Insertion: "<<" ";
    traversal(head);
    cout<<endl;
    head=efficient(head,60);
    cout<<"Linked List After Insertion: "<<" ";
    traversal(head);
    

    return 0;
}

