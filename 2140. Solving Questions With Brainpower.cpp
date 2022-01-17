## https://leetcode.com/contest/weekly-contest-276/problems/solving-questions-with-brainpower/
class Solution {
public:
    long long mp(int i,vector<vector<int>>& questions,vector<long long> &dp){
        if(i>=questions.size())
            return 0;
        if(i==questions.size()-1)
            return questions[i][0];
        long long notskip=-1,skip=-1;
        if(i+questions[i][1]+1 < questions.size()){
            if(dp[i+questions[i][1]+1]!=-1)
                notskip = questions[i][0]+dp[i+questions[i][1]+1];
        }
        if(i+1 < questions.size() && dp[i+1]!=-1)
            skip = dp[i+1];
        if(skip!=-1 && notskip!=-1){
            dp[i] = max(skip,notskip);
        }
        if(skip==-1)
            skip = mp(i+1,questions,dp);
        if(notskip == -1)
            notskip = questions[i][0]+mp(i+questions[i][1]+1,questions,dp);
        dp[i] = max(skip,notskip);
        return dp[i];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),-1);
        return mp(0,questions,dp);
    }
};