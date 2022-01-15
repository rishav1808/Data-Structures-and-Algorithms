#include <iostream>

using namespace std;
struct node{
    int data;
    node* next;
    node(int x){
        data=x;
        next=NULL;
    }
};

void printlist(node *head){
    node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}
node * segregateNodes(node *head)
{
    node *curr=head,*even_start=NULL,*even_end=NULL,*odd_start=NULL,*odd_end=NULL;
    while(curr!=NULL)
    {
        if(curr->data%2==0)
        {
            if(even_start==NULL)
            {
                even_start=curr;
                even_end=curr;
            }
            else{
                even_end->next=curr;
                even_end=curr;
            }
        }
        else{
            if(odd_start==NULL)
            {
                odd_start=curr;
                odd_end=curr;
            }
            else{
                odd_end->next=curr;
                odd_end=curr;
            }
        }
        curr=curr->next;
    }
    if(even_start==NULL || odd_start==NULL)
    return head;
    even_end->next=odd_start;
    odd_end->next=NULL;
    return even_start;
}
int main()
{
    node *head=new node(17);
	head->next=new node(15);
	head->next->next=new node(8);
	head->next->next->next=new node(12);
	head->next->next->next->next=new node(10);
	head->next->next->next->next->next=new node(5);
	head->next->next->next->next->next->next=new node(4);
	printlist(head);
	head=segregateNodes(head);
	printlist(head);

    return 0;
}
