   void mergeList(Node *head)
    {
        Node *temp=head;
        Node *n=head->next;
        while(temp!=NULL)
        {
            Node *copy=new Node(temp->val);
            temp->next=copy;
            copy->next=n;
            temp=n;
            if(n!=NULL)
                n=n->next;
        }
        
    }
    void randomPointer(Node *head)
    {
        Node *temp=head;
        while(temp!=NULL)
        {
          
            if(temp->random!=NULL)
                temp->next->random=temp->random->next;
            
            
            temp=temp->next->next;
        }
    }
    Node* split(Node *head)
    {
        Node *temp=head;
        Node *n=head->next;
        Node *newHead=head->next;
        while(temp!=NULL)
        {
            if(n!=NULL)
                temp->next=n->next;
                temp=n;
            if(n!=NULL)n=n->next;
        }
       // return newHead;
        
        return newHead;
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        mergeList(head);
        randomPointer(head);
        return split(head);
        
    }
};
