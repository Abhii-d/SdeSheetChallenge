/*Problem Statement
You are given two sorted arrays 'A' & 'B' of sizes 'N' & 'M'. You need to find the median of the two arrays when merged. If the total number of elements i.e., N + M is even then the median will be the mean of two medians.
*/

#include<bits/stdc++.h>
double medianFast(vector<int> a, vector<int> b)
{
   // Write your code here.
   if(b.size() < a.size()) return medianFast(b,a);
   int n1= a.size();
   int n2 = b.size();
   
   int low = 0;
   int high = n1;
   while(low<=high){
       
       int count1 = (low+ high)/2;
       int count2 = ((n1+n2 +1)/2) - count1;
       
       int l1 = count1==0 ? INT_MIN : a[count1-1];
       int l2 = count2 ==0 ? INT_MIN : b[count2-1];
       
       int r1 = count1 == n1 ? INT_MAX : a[count1];
       int r2 = count2 == n2 ? INT_MAX : b[count2];
       
       
       if(l1 <= r2 && l2 <= r1){
           if((n1+n2) %2 == 0){
               return double(((double)max(l1,l2) + (double)(double)min(r1,r2))/2);
               
           }
           else {
               return max(l1,l2);
           }
       }
       else if(l1 > r2){
           high = count1-1;
       }
       else{
           low = count1+1;
       }
   }
   
   return 0.0;
   
}
double median(vector<int> a, vector<int> b)
{
    /*int m=b.size();
    for(int i=0;i<m;i++){
        a.push_back(b[i]);
    }
    sort(a.begin(),a.end());
    int n=a.size();
    if(n&1){
        return a[n/2]*1.0;
    }
    else return (a[n/2]+a[(n/2)  -1])/2.0;*/

    return medianFast(a,b);
    
    
    
    /*
    int n=a.size();
    int m=b.size();
    if(n >m ){
        return median(b,a);
    }
    int partation = (n+m+1)/2;
    int low=0;
    int high=(partation);
    int l1,l2,r1,r2,cut1,cut2;
    int mid;
    while(low<=high){
        cut1=low+(high-low)/2;
        cut2=partation-cut1;
        l1=(cut1==0)?INT_MIN:a[cut1-1];
        l2=(cut2==0)?INT_MIN:b[cut2-1];
        r1=(cut1==n)?INT_MAX:a[cut1];
        r2=(cut2==m)?INT_MAX:b[cut2];
        if(l1<=r2 && l2<=r1){
            if((n+m)&1){
                return max(l1,l2)*1.0;
            }
            else return ((max(l1,l2)+min(r1,r2))/2.0);
        }
        else if(l1 > r2)high=cut1-1;
        else low=cut1+1;
    }
    double temp=0.0;
    return temp;*/
}
