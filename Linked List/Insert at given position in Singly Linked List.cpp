/* Insert at given position in Singly Linked List */
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
    return ;
    cout<<head->data<<" ";
    traversal(head->next);
}
node * insertAtBegin(node *head,int pos,int data)
{
    node *temp=new node(data);
    if(pos==1)//If Insertion at 1st position takes place,change head
    {
        temp->next=head;
        return temp;
    }
    node *curr=head;
    for(int i=1;i<=pos-2 && curr!=NULL ;i++)
    curr=curr->next;
    if(curr==NULL)//Corner case where pos is more than elements in LL
    return head;//Ex no=5   pos =10(pos>no+1)
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
    head=insertAtBegin(head,3,100);
     cout<<"Linked List After: "<<" ";
    traversal(head);
    cout<<endl;
    head=insertAtBegin(head,1,200);
     cout<<"Linked List After: "<<" ";
    traversal(head);
    cout<<endl;
    head=insertAtBegin(head,13,300);
     cout<<"Linked List After: "<<" ";
    traversal(head);
    

    return 0;
}
