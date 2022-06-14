#include<bits/stdc++.h>
using namespace std;

void solve(int ind,int sum , vector<int>& num,vector<int>&res,int &n){
    if(n == ind){
        res.push_back(sum);
         return ;
    }
    //picking the element
    solve(ind+1,sum+num[ind],num,res,n);
    
    //not picking the element;
    solve(ind+1,sum,num,res,n);
}


vector<int> subsetSum(vector<int> &num)
{
    /*
    vector<int> res;
    int sum=0;
    int n=num.size();
    solve(0,sum,num,res,n);
    sort(res.begin(),res.end());
    return res;
    */
    vector<int> res;
    int n=num.size();
    int pown=pow(2,n);
    res.push_back(0);
    for(int i=1;i<pown;i++){
        int s=0;
        int sum=0;
        int t=i;
        while(t){
           if(t&1){
               sum += num[s];
           }
            s++;
            t = t>>1;
        }
        res.push_back(sum);
    }
    return res;
}

int main(){

    vector<int> num={1,2,3};
    vector<int> res;
    res=subsetSum(num);
    for(auto i:res){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}