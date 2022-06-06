/*Problem Statement
You are given an array of integers 'ARR' containing N elements. Each integer is in the range [1, N-1], with exactly one element repeated in the array.
Your task is to find the duplicate element.*/


int findDuplicate(vector<int> &arr, int n){


    sort(arr.begin(),arr.end());
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1])//if duplicate ele found return that element
            return arr[i];
    }
}
