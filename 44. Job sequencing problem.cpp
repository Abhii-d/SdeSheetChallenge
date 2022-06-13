/* Problem Statement
You are given a N x 2 2-D array 'Jobs' of 'N' jobs where Jobs[i][0] denote the deadline of i-th job and Jobs[i][1] denotes the profit associated with i-th job.
You will make a certain profit if you complete the job within the deadline associated with it. Each job takes 1 unit of time to be completed, and you can schedule only one job at a particular time.
Your task is to find out the maximum profit that you can make.*/


#include<bits/stdc++.h>
bool cmp(vector<int> &a,vector<int>& b){
    return a[1] > b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
   int n=jobs.size();
    int maxi=0;
    for(int i=0;i<n;i++){
        if(maxi < jobs[i][0])
            maxi=jobs[i][0];
    }
    vector<int> slots(maxi+1,0);
    sort(jobs.begin(),jobs.end(),cmp);
    int profit=0;
    for(int i=0;i<n;i++){
        int dead =jobs[i][0];
//         cout<<jobs[i][0]<<" -> "<<jobs[i][1]<<endl;
        while(dead){
            if(slots[dead] == 0){
//                 cout<<dead<<" ";
                profit += jobs[i][1];
//                 cout<<profit<<" ";
                slots[dead]=1;
                break;
            }
            --dead;
        }
    }
    cout<<endl;
    return profit;
}
