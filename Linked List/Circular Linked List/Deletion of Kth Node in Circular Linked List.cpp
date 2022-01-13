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
node *deleteNode(node *head,int k)
{
    if(k==1)
    return deleteHead(head);
    if(head==NULL)
    return NULL;
    else{
        node *curr=head;
        for(int i=0;i<k-2;i++)
        {
            curr=curr->next;
        }
        node *temp=curr->next;
        curr->next=curr->next->next;
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
    
    head=deleteNode(head,3);
    cout<<"Linked List After Deletion: "<<" ";
    traversal(head);
    
    

    return 0;
}
