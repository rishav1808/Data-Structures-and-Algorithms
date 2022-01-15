#include <iostream>

using namespace std;
struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x)
    {
        data=x;
        next=NULL;
    }
};
void reverse(ListNode *start ,ListNode *end)
{
    ListNode *curr=start,*dummy=NULL,*n=start->next;
      while(dummy!=end)
    {
        
        curr->next=dummy;
        dummy=curr;
        curr=n;
        if(n!=NULL)n=n->next;
    }
}
    ListNode* reverseKGroup(ListNode* head, int k) {
         if(head==NULL || head->next==NULL || k==1)
    return head;
    ListNode *start=head,*end=head;
    int grpsize=k-1;
    while(grpsize--)
    {
        end=end->next;
        if(end==NULL)
        return head;
        
    }
                  
    ListNode *newHead=reverseKGroup(end->next,k);
    reverse(start,end);
    start->next=newHead;
    return end;
        
    }
void traversal(ListNode *head)
{
    if(head==NULL)
    return;
    cout<<head->data<<" ";
    traversal(head->next);
}

int main()
{
    ListNode *head=new ListNode(10);
	head->next=new ListNode(20);
	head->next->next=new ListNode(30);
	head->next->next->next=new ListNode(40);
	head->next->next->next->next=new ListNode(50);
	head->next->next->next->next->next=new ListNode(60);
	head->next->next->next->next->next->next=new ListNode(70);
	cout<<"Linked List: ";
	traversal(head);
	cout<<endl;
	head=reverseKGroup(head,3);
	cout<<" Reversed Linked List: ";
	traversal(head);
	
    

    return 0;
}

