class Deque
{
public:
    // Initialize your data structure.
    int *arr;
    int size;
    int front;
    int rear;
    Deque(int n)
    {
        // Write your code here.
        arr=new int[n];
        size=n;
        front=-1;
        rear=-1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if(isFull())
            return false;
       else if(front==-1)
        {
            front=0;
            rear=0;
            
        }
        else if(front==0 && rear!=size-1)
        {
            front=size-1;
            
        }
        else{
			 front--;
            
        }
        arr[front]=x;
        return true;
           
        

        
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if(isFull())
            return false;
        else if(front==-1)
        {
			front=rear=0;
        }
        else if(rear==size-1 && front!=0)
            rear=0;
        else
            rear++;
        arr[rear]=x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(isEmpty())//When no element is present in Queue
            return -1;
        int x=arr[front];
        if(front==rear)//When only one element is there
        { 
			front=-1;
            rear=-1;
        }
        else if(front==size-1)//Circular Nature of Queue
            front=0;
        else //Normal Flow
            front++;
        return x;
            
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        //When Queue is empty
        if(isEmpty())
            return -1;
        int x=arr[rear];
        //When only 1 element is present
       if(front==rear)
        {
            front=rear=-1;
		}
        //Circular Flow
        else if(rear==0)
            rear=size-1;
        else
            rear--;
        return x;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(front==-1)
            return -1;
            return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(rear==-1)
            return -1;
            return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front==-1)
            return true;
         return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
         if((front==0 && rear==size-1)|| (front !=0 && rear==(front-1)%(size-1)))
             return true;
        return false;
    }
};
