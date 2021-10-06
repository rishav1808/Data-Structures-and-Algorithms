   void merge(long long a[], long long b[], int n, int m) 
        { 
            int i=n-1,j=0;//Traverse Left array from end and Right array from start
            while(i>=0 && j<m)//Normal Traversal of Both the arrays
            {
                if(a[i]>=b[j])//Both the arrays are sorted in themselves.
                //And in the end we want both the arrays to be sorted wrt both of them
                {
                    swap(a[i],b[j]);//If ele in left>=ele in right,to keep them sorted wrt to each other
                    //we have to keep smaller eles in left and larger ele in right.SO that's why we swap
                    i--;j++;//Move the pointers to further check any other such cases
                }
                else//Lets suppose that the last ele of Left array<first ele of Right array
                {//Since the arrays are sorted this means that last ele of left<all eles of Right array
                //And if last ele of left<all ele of Right array, then it means all ele of left<all ele of right
                //This is so coz last ele of left is the largest ele among the Left array and if it is smaller than
                //all ele of Right so, all eles of left<all eles of right.
                //So the now the resultant array will automatically be sorted so we can break out
                    break;
                }
            }
            sort(a,a+n);//due to swapping the left array may not be sorted
            sort(b,b+m);
            
        } 
