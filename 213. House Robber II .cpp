## https://leetcode.com/problems/house-robber-ii/
class Solution {
public:
    int profit(vector<int> &nums,int start,int end){
        vector<int> response(end-start+2,0);
        response[0] = 0;
        if(end-start+1>0)
            response[1] = nums[start];
        for(int i=2;i<end-start+2;i++){
            response[i] = max(response[i-1],nums[start+i-1]+response[i-2]);
        }
        return response[end-start+1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        return max(profit(nums,0,n-2),profit(nums,1,n-1));
    }
};