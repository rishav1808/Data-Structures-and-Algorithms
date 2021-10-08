#include <iostream>

using namespace std;
void cycleSort(int *a,int n)
{
    int index=0;//Iterator used to Traverse the Array
    while(index<n)
    {
      int correctIndex=a[index]-1;//The element which we are scanning,what will be that element's correctIndex??
                                //So we know that correctIndex=value-1{Ex: correctIndex of 3 would be 3-1=2 i.e a[i]-1 where a[i]=3}
      if(index!=correctIndex)//If currrent value that we are scanning is not in its correct position then send it to its correct position
      {
          swap(a[index],a[correctIndex]);
      }
      else
      index++;//else everything is fine and let's move on to the next index
    }
    
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int main()
{
    int a[]={3,5,2,1,4};
    int n=5;
    cycleSort(a,n);

    return 0;
}
