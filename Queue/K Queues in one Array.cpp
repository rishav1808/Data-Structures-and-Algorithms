#include <bits/stdc++.h>

using namespace std;

class KQueue{
    public:
        int *arr;
        int *next;
        int *front;
        int *rear;
        int freespot;
    
    public:
        KQueue(int n, int k){
            arr=new int[n];
            next=new int[n];
            front=new int[k];
            rear=new int[k];
            freespot=0;
            
            for(int i=0;i<n-1;i++)
            next[i]=i+1;
            next[n-1]=-1;
            
            for(int i=0;i<k;i++)
            {
                front[i]=-1;
                rear[i]=-1;
            }
        }
        
        void enqueue(int x,int qn)
        {
            //Overflow Condition
            if(freespot==-1)
            {
                cout<<"Queue is Full"<<endl;
                return;
            }
            //Finding the freespot to insert the Value
            int index=freespot;
            //Updating the freespot
            freespot=next[index];
            
            //If first element is inserted
            if(front[qn-1]==-1)
            front[qn-1]=index;
            //else if elements are already present then make links
            else
            next[rear[qn-1]]=index;
            //Index is filling so update the next array
            next[index]=-1;
            //Update rear
            rear[qn-1]=index;
            //Push the elements
            
            arr[index]=x;
            
        
        
            
            
        }
        
        int dequeue(int qn)
        {
            //UnderFlow
            if(front[qn-1]==-1)
            {
                cout<<"Queue is Empty"<<endl;
                return -1;
            }
            //Find Index from where to Pop
            
            int index=front[qn-1];
            
            //Move front
            front[qn-1]=next[index];
            //next freespot after index
            next[index]=freespot;
            //Let freespot point to 1st empty space
            freespot=index;
            return arr[index];
        }
        
        
};

int main()
{
    KQueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);
    
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;

    return 0;
}
