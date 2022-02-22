## https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> response(n+1,0);
        if(n>0)
            response[1]=1;
        if(n>1)
            response[2]=2;
        for(int i=3;i<n+1;i++)
            response[i]=response[i-1]+response[i-2];
        return response[n];
    }
};


class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<n+1;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};