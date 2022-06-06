/*Problem Statement
Ninja has been given two sorted integer arrays/lists ‘ARR1’ and ‘ARR2’ of size ‘M’ and ‘N’. Ninja has to merge these sorted arrays/lists into ‘ARR1’ as one sorted array. You may have to assume that ‘ARR1’ has a size equal to ‘M’ + ‘N’ such that ‘ARR1’ has enough space to add all the elements of ‘ARR2’ in ‘ARR1’.*/

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2,int m, int n) {
    int idx=m+n-1;//index for sorted array pointing to last of arr1
    int idx1=m-1;//index for arr1 
    int idx2=n-1;//index for arr2
    while(idx1 >=0 && idx2>=0){ // start putting element from last 
        if(arr1[idx1] > arr2[idx2]){
            arr1[idx--]= arr1[idx1--];
        }
        else{
            arr1[idx--]=arr2[idx2--];
        }
    }
    while(idx2>=0){
        arr1[idx--]=arr2[idx2--];
    }
    return arr1;
}