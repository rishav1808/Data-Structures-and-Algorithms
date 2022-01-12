/* Deletion of Node from End of Singly Linked List */
enclude <iostream>

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
node *deleteLast(node *head)
{
    if(head==NULL)//If LL is empty
    return NULL;
    if(head->next==NULL)//If only 1 element is present in LL
    {
        delete head;
        return NULL;
    }
    node *curr=head;
    while(curr->next->next!=NULL)
    curr=curr->next;
    curr->next=NULL;
    return head;
}

int main()
{    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    cout<<"Linked List Before: "<<" ";
    traversal(head);
    cout<<endl;
    
   head=deleteLast(head);
    cout<<"Linked List After: "<<" ";
    traversal(head);
     head=deleteLast(head);
    cout<<"Linked List After: "<<" ";
    traversal(head);
     head=deleteLast(head);
    cout<<"Linked List After: "<<" ";
    traversal(head);
    
    

    return 0;
}
