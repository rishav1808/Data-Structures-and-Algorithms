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

node * deleteHead(node *head)
{
    if(head==NULL)
    return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    else{
        node *curr=head;
        while(curr->next!=head)
        curr=curr->next;
        curr->next=head->next;
        delete head;
        return curr->next;
    }
}
node * efficient(node *head)
{
    if(head==NULL)
    return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    else{
        head->data=head->next->data;//Making 1st and 2nd node same
        node *temp=head->next;//Pointer to the 2nd Node which will be deleted
        head->next=head->next->next;
        delete temp;
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
    cout<<"Linked List Before Deletion: "<<" ";
    traversal(head);
    cout<<endl;
    head=deleteHead(head);
    cout<<"Linked List After Deletion: "<<" ";
    traversal(head);
    cout<<endl;
    head=efficient(head);
    cout<<"Linked List After Deletion: "<<" ";
    traversal(head);
    
    

    return 0;
}
