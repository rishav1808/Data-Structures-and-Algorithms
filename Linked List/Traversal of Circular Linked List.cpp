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
    traversal(head);
    
    return 0;
}
