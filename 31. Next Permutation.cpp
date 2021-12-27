## https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),k=n-2;
        while(k!=-1 && nums[k]>=nums[k+1])
            k--;
        if(k==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        else{
            int l = n-1;
            while(nums[l]<=nums[k])
                l--;
            swap(nums[k],nums[l]);
            sort(nums.begin()+k+1,nums.end());
        }
    }
};