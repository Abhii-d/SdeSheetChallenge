/*Problem Statement
You are given a string 'S'. Your task is to partition 'S' such that every substring of the partition is a palindrome. You need to return all possible palindrome partitioning of 'S'.
Note: A substring is a contiguous segment of a string.
*/


bool isPalindrome(string s,int begin,int end){
    while(begin<=end){
        if(s[begin]!=s[end])return false;
        begin++;
        end--;
    }
    return true;
}


void fun(string s,int index,vector<string>&path,vector<vector<string>> &res){
    if(index == s.size()){
        res.push_back(path);
        return;
    }
    
    for(int i=index;i<s.size();i++){
        if(isPalindrome(s , index , i)){
            path.push_back(s.substr(index,i-index+1));
            fun(s,i+1,path,res);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> res;
    vector<string > path;
    fun(s,0,path,res);
    return res;
}