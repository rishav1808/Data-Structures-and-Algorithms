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
node *removeDuplicate(node *head)
{
    node *curr=head;
    if(curr!=NULL)
    {
        while(curr->next!=NULL)
    {
        if(curr->data==curr->next->data)
        {
            node *temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
        }
        else
        curr=curr->next;
    }
        
    }
    
    return head;
}
int main()
{
     node *head=new node(10);
    head->next=new node(10);
    head->next->next=new node(20);
    head->next->next->next=new node(30);
    head->next->next->next->next=new node(30);
    head->next->next->next->next->next=new node(30);
    traversal(head);
    cout<<endl;
    head=removeDuplicate(head);
    traversal(head);
    

    return 0;
}
