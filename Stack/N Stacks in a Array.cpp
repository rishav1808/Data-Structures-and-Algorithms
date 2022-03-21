class NStack
{
public:
    // Initialize your data structure.
    int *arr;
    int *top;
    int *next;
    int freespot;
    NStack(int N, int S)
    {
        arr=new int[S];
        top=new int[N];
        next=new int[S];
        for(int i=0;i<N;i++)
            top[i]=-1;
        for(int i=0;i<S-1;i++)
            next[i]=i+1;
        next[S-1]=-1;
        freespot=0;
        
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(freespot==-1)
            return false;
        int index=freespot;
        freespot=next[index];
        arr[index]=x;
        next[index]=top[m-1];
        top[m-1]=index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1]==-1)
            return -1;
        int index=top[m-1];
        top[m-1]=next[index];
        next[index]=freespot;
        freespot=index;
        return arr[index];
    }
};
