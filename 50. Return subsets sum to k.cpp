/*Problem Statement
Given an integer array 'ARR' of size 'N' and an integer 'K', return all the subsets of 'ARR' which sum to 'K'.
Subset of an array 'ARR' is a tuple that can be obtained from 'ARR' by removing some (possibly all) elements of 'ARR'.
*/

void find(int idx,int n,int k,vector<int>&arr,vector<int>ans , vector<vector<int>>&res){
    if(idx==n){
        if(k==0){
            res.push_back(ans);
        }
        return ;
    }    
    ans.push_back(arr[idx]);
    find(idx+1,n,k-arr[idx],arr,ans,res);
    ans.pop_back();
    
    find(idx+1,n,k,arr,ans,res);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> res;
    vector<int> ans;
    find(0,n,k,arr,ans,res);
    return res;
    /*
    int nn=pow(2,n);
    vector<vector<int>>res;
    for(int i=1;i<nn;i++){
        int t=i;
        int sum=0;
        int s=0;
        vector<int> temp;
        while(t){
            if(t&1){
                sum+=arr[s];
                temp.push_back(arr[s]);
            }
            s++;
            t=t>>1;
        }
        if(sum ==k){
            res.push_back(temp);
        }
    }
    return res;*/
    
}