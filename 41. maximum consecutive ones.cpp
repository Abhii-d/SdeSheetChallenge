/* Problem Statement
Given a binary array 'ARR' of size 'N', your task is to find the longest sequence of continuous 1’s that can be formed by replacing at-most 'K' zeroes by ones. Return the length of this longest sequence of continuous 1’s.
*/

int longestSubSeg(vector<int> &arr , int n, int k){
    
    vector<int> v(n,0);
    int i=0;
    int mx=0;
    for(int j=0;j<n;j++){
        if(arr[j]==0){
            if(k>0){
                k--;
                v[j]=1;
            }
            else{
                while(k <= 0){
                    if(v[i]==1){
                        v[i]=0;
                        k++;
                        i++;
                    }
                    else
                    i++;
                }
                v[j]=1;
                k--;
            }
        }
        mx=max(mx,j-i+1);
    }
    return mx;
//     int mx=0;
//     for(int i=0;i<n;i++){
//         int t=i;
//         int ct=k;
//         while(t < n ){
//             if(arr[t]==1)t++;
//             else{
//                 if(ct>0){
//                     t++;ct--;
//                 }
//                 else break;
//             }
//         }
//         mx=max(mx,t-i);
//         mx=min(mx,n);
//     }
//     return mx;
}
