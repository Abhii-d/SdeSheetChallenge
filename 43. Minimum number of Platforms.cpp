/*Problem Statement
You have been given two arrays, 'AT' and 'DT', representing the arrival and departure times of all trains that reach a railway station.
Your task is to find the minimum number of platforms required for the railway station so that no train needs to wait.*/


int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);
    int platform=1,ans=1,i=1,j=0;
    while(i<n && j<n){
        if(at[i]<=dt[j]){
            platform++;
            i++;
        }
        else if(at[i]>dt[j]){
            platform--;
            j++;
        }
        if(platform>=ans)
            ans=platform;
    }
    return ans;
    
    /* TLE
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        arr.push_back({at[i],dt[i]});
    }
    vector<int> res;
    sort(arr.begin(),arr.end());
    res.push_back(arr[0].second);
    int isdone=0;
    for(int i=1;i<n;i++){
        isdone=0;
        for(auto& ele : res){
            if( arr[i].first > ele){
                ele=arr[i].second;
//                 cout<<ele<<" ";
                isdone=1;
                break;
            }
        }
        if(isdone==0){
            res.push_back(arr[i].second);
        }
    }
//     for(auto i:res){
//         cout<<i<<" ";
//     }
//     cout<<endl;
    return res.size();*/
}