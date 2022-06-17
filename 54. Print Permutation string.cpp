/*Problem Statement
You are given an input string 'S'. Your task is to find and return all possible permutations of the input string.
*/

#include<bits/stdc++.h>
void nextPermutation(string &s,int n){
    int k=n-2;
    while(k >=0){
        if(s[k] < s[k+1])break;
        k--;
    }
    if(k<=0 && s[0] >= s[1]){
        reverse(s.begin(),s.end());
        return ;
    }
    int e=n-1;
    while(e >k){
        if(s[e] > s[k])break;
        e--;
    }
    char temp=s[e];
    s[e]=s[k];
    s[k]=temp;
    reverse(s.begin()+k+1,s.end());
    
}

void recurPermut(int idx,string &s,vector<string>&res,int n){
    if(idx == n){
        res.push_back(s);
        return ;
    }
    for(int i=idx;i<n;i++){
        swap(s[idx],s[i]);
        recurPermut(idx+1,s,res,n);
        swap(s[idx],s[i]);
    }
}

vector<string> findPermutations(string &s) {
    int n=s.size();
    
    vector<string> res;
    recurPermut(0,s,res,n);
    return res;
    /*int n=s.size();
    int nfact=1;
    for(int i=1;i<=n;i++){
        nfact*=i;
    }
//     cout<<nfact<<endl;
    vector<string>res;
    for(int i=0;i<nfact;i++){
        nextPermutation(s,n);
        res.push_back(s);
//         cout<<s<<endl;
    }
    return res;*/
}