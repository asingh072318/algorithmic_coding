## https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> response;
        for(int i=0;i<nums.size();i++){
            # if num[i]+b = target then check if b already found in array
            if(mp[target-nums[i]] != 0)
            {
                response.push_back(i);
                response.push_back(mp[target-nums[i]]-1);
                return response;
            }
            mp[nums[i]] = i+1;
        }
        return response;
    }
};