/*Problem Statement
Aahad and Harshit always have fun by solving problems. Harshit took a sorted array consisting of distinct integers and rotated it clockwise by an unknown amount. For example, he took a sorted array = [1, 2, 3, 4, 5] and if he rotates it by 2, then the array becomes: [4, 5, 1, 2, 3].
After rotating a sorted array, Aahad needs to answer Q queries asked by Harshit, each of them is described by one integer Q[i]. which Harshit wanted him to search in the array. For each query, if he found it, he had to shout the index of the number, otherwise, he had to shout -1.
For each query, you have to complete the given method where 'key' denotes Q[i]. If the key exists in the array, return the index of the 'key', otherwise, return -1.
*/

int  pivot(int* arr, int n)

{

   int lo = 0, hi = n - 1, mid = lo + (hi - lo) / 2;

   while (lo < hi)

   {

       if (arr[mid] >= arr[0])

       {

           lo = mid + 1;

       }

       else

       {

           hi = mid;

       }

       mid = lo + (hi - lo) / 2;

   }

  return lo;

}

int binary_search(int arr[],int lo,int hi,int key)

{

  int mid=lo+(hi-lo)/2;

   while(lo<=hi)

   {  

     if(arr[mid]==key)

        {

            return mid;

        }

        else if(arr[mid]<key){

            lo=mid+1;

        }

        else{

            hi=mid-1;

        }

        mid=lo+(hi-lo)/2;

   }

return -1;

}

int search(int* arr, int n, int key) {

   // Write your code here.

   int s=0,e=n-1,ans=0;

   int pivot_res=pivot(arr,n);

   if(arr[pivot_res]<=key && key<=arr[e])

   {

       //second line

 ans= binary_search(arr,pivot_res,e,key);

   }

   else

   {

  //first line 

       ans=binary_search(arr,s,pivot_res-1,key);

   }

   return ans;

}