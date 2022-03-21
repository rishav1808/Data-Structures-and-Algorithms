class Queue {
public:
    int *arr;
     int qfront;
    int rear;
    Queue() {
        // Implement the Constructor
        arr=new int[1000000];
        qfront=0;
        rear=0;
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront==rear)
            return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear==1000000)
            return;
        arr[rear]=data;
        rear++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront==rear)
            return -1;
        else{
            int x=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear)
            {
                qfront=0;
                rear=0;
            }
            return x;
        }
    }

    int front() {
        if(qfront==rear)
            return -1;
        else
            return arr[qfront];
    }
};
