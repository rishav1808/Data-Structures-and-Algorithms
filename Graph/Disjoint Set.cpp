#include <bits/stdc++.h>

using namespace std;

class DisjointSet{
    public:
    int *rank;
    int *parent;
    int node;
    
    DisjointSet(int n)
    {
        rank= new int[n+1];
        parent= new int[n+1];
        this->node=n;
    }
    
    void makeSet(){
        for(int i=1;i<=node;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    
    int findParent(int node)
    {
        if(node = parent[node])
        return node;
        
        // return findParent(parent[node]) -->Not Path Compressed
       return parent[node]=findParent(parent[node]);
       // return parent[node];
    }
    
    void unionSet(int node1 ,int node2)
    {
        //Step-1 find parent of both the nodes
        node1 = findParent(node1);
        node2 = findParent(node2);
        if(node1==node2)
        return;
        else
        {
            if(rank[node1]==rank[node2])
            {
                parent[node2]=node1;
                rank[node1]++;
            }
            else if(rank[node1]<rank[node2])
            {
                parent[node1]=node2;
            }
            else{
                parent[node2]=node1;
            }
        }
    }
};

int main()
{
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    DisjointSet d1(7);
    d1.makeSet();
   /* for(int i=1;i<=n;i++)
    {
        cout<<"Parent of "<<i<<" is "<<d1.findParent(i);
        cout<<endl;
    }*/
    d1.unionSet(1,2);
    d1.unionSet(2,3);
    cout<<"Parent of "<<3<<" is "<<d1.findParent(3)<<endl;
    d1.unionSet(4,5);
    cout<<"Parent of "<<5<<" is "<<d1.findParent(5)<<endl;
    d1.unionSet(6,7);
    cout<<"Parent of "<<7<<" is "<<d1.findParent(7)<<endl;
    d1.unionSet(5,6);
    cout<<"Parent of "<<6<<" is "<<d1.findParent(6)<<endl;
    d1.unionSet(1,7);
    cout<<"Parent of "<<7<<" is "<<d1.findParent(7)<<endl;
    cout<<"Parent of "<<3<<" is "<<d1.findParent(3)<<endl;
    
  
    

    return 0;
}
