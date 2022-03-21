class CircularQueue{
    public:
    // Initialize your data structure.
    int *arr;
    int size;
    int front;
    int rear;
    CircularQueue(int n){
        // Write your code here
        arr=new int[n];
        size=n;
        front=-1;
        rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if((front==0 && rear==size-1) || (rear==(front-1)%(size-1)))
            return false;
        else if(front==-1)
        {
            front=0,rear=0;
            arr[rear]=value;
            //return true;
        }
       else if(rear==size-1 && front!=0)
        {
            rear=0;
            arr[rear]=value;
           
}
        else{
            rear++;
            arr[rear]=value;
        }
            return true;
        
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(front==-1)
            return -1;
        int ans=arr[front];
        arr[front]=-1;
      //Only one element
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else if(front==size-1)
            front=0;
        else
            front++;
        return ans;
        
    }
};
