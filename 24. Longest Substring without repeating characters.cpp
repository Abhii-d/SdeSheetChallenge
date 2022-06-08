/*Problem Statement
Given a string input of length n, find the length of the longest substring without repeating characters i.e return a substring that does not have any repeating characters.
Substring is the continuous sub-part of the string formed by removing zero or more characters from both ends.*/

#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
   
    vector<int> freqChar(26,0);//for making visited
    //char true
    int mxlength = 1;
    int i=0;
    int j=0;
    int n=input.size();
    while(j < n){
        if(freqChar[input[j] -'a']==0){
            freqChar[input[j] -'a']=1;
        }
        else{
            mxlength=max(mxlength,j-i);

            while(i <= j && freqChar[input[j] -'a'] > 0){
                freqChar[input[i] -'a'] =0;
                i++;
            }
            freqChar[input[j] -'a']=1;
        }
        j++;
    }
    mxlength=max(mxlength,j-i);
    return mxlength;
}