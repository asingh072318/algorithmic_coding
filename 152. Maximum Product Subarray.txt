## https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(),minVal = nums[0], maxVal=nums[0];
        int res = maxVal;
        for(int i=1;i<n;i++){
            int maxP = maxVal * nums[i];
            int minP = minVal * nums[i];
            maxVal = max({nums[i],minP,maxP});
            minVal = min({nums[i],minP,maxP});
            if(res < maxVal)
                res = maxVal;
        }
        return res;
    }
};