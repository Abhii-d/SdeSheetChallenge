/*Problem Statement
You have been given two integers ‘N’ and ‘K’. Your task is to find the K-th permutation sequence of numbers from 1 to ‘N’. The K-th permutation is the K-th permutation in the set of all sorted permutations of string 1 to ‘N’.
*/

#include<bits/stdc++.h>
void nextpermutation(string &s,int n){
    int k=n-2;
    while(k>=0){
        if(s[k] < s[k+1])
            break;
        k--;
    }
    if(k==0 && s[0]>s[1]){
        reverse(s.begin(),s.end());
        return ;
    }
    int temp=n-1;
    while(s[k] > s[temp])temp--;
    char t=s[temp];
    s[temp] =s[k];
    s[k] =t;
    
    reverse(s.begin()+k+1,s.end());

}

string kthPermutation(int n, int k) {
//     k=k%(n+1);
    
    int set=1;
    int ans=1;
    int temp =k;
    
    while(temp){
        if(temp/set){
            ans*=set;
            temp=temp/set;
           set++;
        }
        else
        temp=temp/set;
    }
    set--;
    
    
    string s="";
    for(int i=1;i<=n;i++){
        s.push_back(char(i) +'0');
    }
    set=n-set;
    reverse(s.begin()+set,s.end());
    if(k%ans==0 && k/ans==1){
        return s;
    }
    
    for(int i=ans ;i < k;i++){
        nextpermutation(s,n);
//         cout<<s<<endl;
    }
    return s;
}
