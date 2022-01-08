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