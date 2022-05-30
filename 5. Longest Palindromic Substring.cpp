##https://leetcode.com/problems/longest-palindromic-substring/submissions/
class Solution {
public:
    string longestPalindrome(string s) {
        string response;
        int maxLength = 0,n = s.length();
        vector<vector<int>> memo(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            memo[i][i]=true;
            response=s[i];
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                memo[i][i+1]=true;
                maxLength=2;
                response=s.substr(i,2);
            }
            else
                memo[i][i+1]=false;
        }
        for(int i=n-3;i>=0;i--){
            for(int j=n-1;j>i+1;j--){
                if(memo[i+1][j-1]==1 && s[i]==s[j]){
                    memo[i][j]=true;
                    if(j-i+1>maxLength){
                        maxLength=j-i+1;
                        response = s.substr(i,maxLength);
                    }
                }
                else
                    memo[i][j]=false;
            }
        }
        return response;
    }
};