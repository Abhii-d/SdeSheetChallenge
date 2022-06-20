/*Problem Statement
Ninja wants to serve food to needy people. So, he bought Ladoos from a sweet shop and placed them on plates. There can be any number of Ladoos present in a plate.
Plates containing Ladoos are placed in two rows. Each row is sorted in increasing order by the number of Ladoos in a plate.
*/


#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &arr1, vector<int> &arr2, int n, int m, int k) {
    /*if(n  > m){
        return ninjaAndLadoos(row2,row1,m,n,k);
    }
    int l1,l2,r1,r2;
    int lo = 0;
    int high=min(k,n);
    int cut1,cut2;
    while(lo <= high){
        cut1 = lo+(high-lo)/2;
        cut2 = k-cut1;
        l1=(cut1==0)?INT_MIN:row1[cut1-1];
        l2=(cut2==0)?INT_MIN:row2[cut2-1];
        r1=(cut1==n)?INT_MAX:row1[cut1];
        r2=(cut2==m)?INT_MAX: row2[cut2];
        if(l1<=r2 && l2 <= r2){
            return max(l1,l2);
        }
        else if(l1 > r2)high=cut1-1;
        else lo =cut1+1;
        
    }
    return -1;*/
    if(m<n){
            return ninjaAndLadoos(arr2,arr1,m,n,k);
        }
        
        int low=max(0,k-m);
        int high=min(k,n);
        
        while(low<=high){
        int p1=(low+high)/2;
        int p2=k-p1;
        
        int l1=p1==0 ? INT_MIN : arr1[p1-1];
        int l2=p2==0 ? INT_MIN : arr2[p2-1];
        int r1=p1==n ? INT_MAX : arr1[p1];
        int r2=p2==m ? INT_MAX : arr2[p2];
        
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2){
            high=p1-1;
        }
        else{
            low=p1+1;
        }
        }
        return 1;
}