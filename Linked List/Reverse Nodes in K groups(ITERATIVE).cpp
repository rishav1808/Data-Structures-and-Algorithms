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
void traversal(ListNode*head)
{
    if(head==NULL)
    return;
    cout<<head->data<<" ";
    traversal(head->next);
}
ListNode *reverseKNodes(ListNode*head,int k )
{
    if(head==NULL || head->next==NULL || k==1)
    return head;
    ListNode *dummy=new ListNode(-1);
    dummy->next=head;
    ListNode *end=head,*beforeStart=dummy;
    int i=0;
    while(end!=NULL)
    {
        i++;
        if(i%k==0)
        {
            ListNode *start=beforeStart->next,*afterEnd=end->next;;
            
            ListNode*curr=start,*next=start->next,*prev=beforeStart;
            while(prev!=end)
            {
                curr->next=prev;
                prev=curr;
                curr=next;
                if(next!=NULL)
                next=next->next;
            }
            beforeStart->next=end;
            start->next=afterEnd;
            beforeStart=start;
            end=afterEnd;
            
        }
        else
        end=end->next;
    }
    return dummy->next;
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
	head=reverseKNodes(head,3);
	cout<<"Reversed Linked List: ";
	traversal(head);

    return 0;
}
