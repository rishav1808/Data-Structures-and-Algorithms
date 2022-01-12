/* Search in a Linked List (Iterative and Recursive) */
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
int pos=1;
int rsearch(node *head,int key)
{
    if(head==NULL)
    return -1;
    if(head->data==key)
    return 1;
    else
    {
        int res=rsearch(head->next,key);
        if(res==-1)
        return -1;
        else
        return(res+1);
    }
}
int search(node *head,int key)
{
    int count=1;
    node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        return count;
        else
        {
            count++;
            temp=temp->next;
        }
        

        
    }
    return -1;
}
int main()
{
     node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    cout<<rsearch(head,30);

    return 0;
}
