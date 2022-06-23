/*Problem Statement
You are given a non-empty string S containing no spaces’ and a dictionary of non-empty strings (say the list of words). You are supposed to construct and return all possible sentences after adding spaces in the originally given string ‘S’, such that each word in a sentence exists in the given dictionary.
*/

//fails for last test case

bool solve(string &s,int idx,string ans,string word,vector<string > & res,vector<string>& dictionary,int n){
    if(idx>=n){
        res.push_back(ans);
        return false;
    }
    for(int j=idx;j<n;j++){
        word+=s[j];
        for(int k=0;k<dictionary.size();k++){
            if(dictionary[k]==word){
                int p=ans.length();
                if(ans.empty()) ans=word;
                else ans=ans+" "+word;
                if(solve(s,j+1,ans,"",res,dictionary,n))return true;
                ans.erase(p);
                
            }
            
            
        }
    }
    return false;
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    string ans="";
    vector<string> res;
    string word="";
    int n=s.length();
    solve(s,0,ans,word,res,dictionary,n);
    return res;

}