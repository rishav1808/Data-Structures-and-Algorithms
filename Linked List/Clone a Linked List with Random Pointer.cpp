#include <bits/stdc++.h>

using namespace std;
struct Node{
    int data;
    Node *next,*random;
    Node(int x)
    {
        data=x;
        random=next=NULL;
    }
};
void traversal(Node *head)
{
    if(head==NULL)
    return;
    cout<< "Data = "<<head->data<<",Random= "<<head->random->data<<" ";
    traversal(head->next);
}
Node *cloneList(Node *head)
{
    Node *temp=head;
    unordered_map<Node *,Node *>mp;
    while(temp!=NULL)
    {
        Node *copy=new Node(temp->data);
        mp[temp]=copy;
        temp=temp->next;
        
    }
    temp=head;
    while(temp!=NULL)
    {
        mp[temp]->next=mp[temp->next];
        mp[temp]->random=mp[temp->random];
        temp=temp->next;
    }
    return mp[head];
}
int main()
{
   	Node* head = new Node(10); 
    head->next = new Node(5); 
    head->next->next = new Node(20); 
    head->next->next->next = new Node(15); 
    head->next->next->next->next = new Node(20); 
    
    head->random = head->next->next;
    head->next->random=head->next->next->next;
    head->next->next->random=head;
    head->next->next->next->random=head->next->next;
    head->next->next->next->next->random=head->next->next->next;
    
 cout << "Original list : \n"; 
    traversal(head); 
  
    cout << "\nCloned list : \n"; 
    Node *cloned_list = cloneList(head); 
    traversal(cloned_list); 
    return 0;
}
