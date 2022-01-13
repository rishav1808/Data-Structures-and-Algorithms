#include <iostream>

using namespace std;
struct node{
    int data;//Data that the node stores
    node *next;//Pointer of type node which stores address of next node in the list
    node(int x)node//Constructor 
    {
        data=x;
        next=NULL;
    }
};
void traversal(node *head)//Function that traverses and print the linked list
{
    node *x=head;//A pointer that stores the address of the first node
    while(x!=NULL)//While x does not store the address of nothing
    {
        cout<<x->data<<" ";//Print the data part of the node pointed by x
        x=x->next;//Now x points to the address stored in the first node i.e. address of 2nd node
    }
}
int main()
{
   node *head=new node(10);
   head->next=new node(20);
   head->next->next=new node(30);
   traversal(traversal);
   

    return 0;
}

