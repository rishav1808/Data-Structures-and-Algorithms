#include <bits/stdc++.h>

using namespace std;
struct node
{
  int data;
  node *next;
    node (int x)
  {
    data = x;
    next = NULL;
  }
};
void
traversal (node * head)
{
  if (head == NULL)
    return;
  cout << head->data << " ";
  traversal (head->next);
}

node *
reverseLinkedList (node * head)
{
  if (head == NULL || head->next == NULL)
    return head;
  node *newHead = reverseLinkedList (head->next);
  head->next->next = head;
  head->next = NULL;
  return newHead;
}

int main()
{
      node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    head->next->next->next->next=new node(50);
 
    cout<<"Linked List: "<<" ";
    traversal(head);
    cout<<endl;
    head=reverseLinkedList(head);
    
    cout<<"Reversed Linked List: "<<" ";
    traversal(head);
    

    return 0;
}

