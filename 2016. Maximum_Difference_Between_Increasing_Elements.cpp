## https://leetcode.com/problems/maximum-difference-between-increasing-elements/
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxD = -1;
        int minel = nums[0];
        for(int i=1;i<nums.size();i++){
            if(minel<nums[i])
                maxD = max(maxD,nums[i]-minel);
            minel = min(nums[i],minel);
        }
        return maxD;
    }
};