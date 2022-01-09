## https://leetcode.com/problems/min-cost-climbing-stairs/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> response(n+1,-1);
        if(n>0)
            response[0] = 0;
        if(n>1)
            response[1] = 0;
        for(int i=2;i<n+1;i++){
            response[i] = min(cost[i-1]+response[i-1],cost[i-2]+response[i-2]);
        }
        return response[n];
    }
};