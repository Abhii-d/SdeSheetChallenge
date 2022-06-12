/* Problem Statement
You are given a sorted integer array' ARR' of size 'N'. You need to remove the duplicates from the array such that each element appears only once. Return the length of this new array.*/

int removeDuplicates(vector<int> &arr, int n) {
    int count =0;
    for(int i=0;i<n-1;i++){
        if(arr[i] !=arr[i+1])count++;
    }
    count++;
    return count;
}