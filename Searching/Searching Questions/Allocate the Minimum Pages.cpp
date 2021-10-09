//Allocate Minimum Number of pages
/* You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate contagious books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations and print this minimum value. 

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding). */

/* Steps
1. First Identify low and high which are the range of pages among which our answer will lie.
2.After that Apply Binary Search on our Range of pages
3.Now calculate mid, for this value of mid check that the allocation is possible or not by using isPossible fxn.
4. If so update ans, and now look for lesser value of mid and try to find a new answer so update high
5. Now if the allocation is not possible then just increase the value of mid by increasing low
6. At the end return the ans which gives the minimum possible pages 
7. In isPossible fxn we just check that if the the student can read the current book or not(pages+a[i]<=mid)
    If so then we include these pages for the student .Else if student is not able to read the new pages(pages+a[i]>mid)
    then we give these new pages to the new student{ student++; pages=a[i] }
 */
#include <iostream>

using namespace std;
bool isPossible(int *a,int mid,int m,int n)
{
    int pages=0,student=1;
    for(int i=0;i<n;i++)
    {
        if(pages+a[i]<=mid)
        pages+=a[i];
        else
        {
            student++;
            pages=a[i];
        }
    }
    return(student<=m);
}
int findPages(int *a,int n,int m)
{
    int low=0,high=0;
    for(int i=0;i<n;i++)
    {
        low=max(low,a[i]);
        high+=a[i];
    }
    int ans=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(isPossible(a,mid,m,n)==true)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
    
}
int main()
{
    int a[]={12,34,67,90};
    int n=4;
    int m=2;
    cout<<findPages(a,n,m);

    return 0;
}

