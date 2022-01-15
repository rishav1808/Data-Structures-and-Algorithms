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
int firstCycleNode(node *head)//To check if Loop exists or not
{
    if(head==NULL || head->next==NULL)//List is empty or only 1 item that too points to Null
    return false;
    node *curr=head,*slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL)//We move fast 2 times so it is possible that
    {                               //If fast->next==NULL then fast->next->next will give excpetion
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        break;
    }
    if(slow!=fast)
    return -1;
    slow=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow->data;
}

int main()
{
    node *head=new node(15);
	head->next=new node(10);
	head->next->next=new node(12);
	head->next->next->next=new node(20);
	head->next->next->next->next=head->next;
	
	//head->next->next->next->next=NULL;
	cout<<firstCycleNode(head);

    return 0;
}

