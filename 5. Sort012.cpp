/*Problem Statement
You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.*/


void sort012(int *arr, int n)
{
    int i=0;//for 0
    int m=0;//for 1
    int k=n-1;//for 2
    while(m<=k){
       if(arr[m]==0)//if arr[m]=0 swap with i
       {    
           swap(arr[m],arr[i]);
           m++;i++;
        }
        if(arr[m]==1)
            m++;
        if(m<=k){
            if(arr[m]==2){
                swap(arr[m],arr[k]);
                k--;
            }    
        }
    }
}