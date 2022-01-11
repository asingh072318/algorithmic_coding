## https://leetcode.com/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> response(n+1,0);
        response[0] = 0;
        if(n>0)
            response[1] = nums[0];
        for(int i=2;i<n+1;i++){
            response[i]=max(response[i-1],nums[i-1]+response[i-2]);
        }
        return response[n];
    }
};