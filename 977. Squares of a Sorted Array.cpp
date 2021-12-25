## https://leetcode.com/problems/squares-of-a-sorted-array/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        vector<int> response;
        while(response.size()!=nums.size()){
            if(abs(nums[i])>abs(nums[j])){
                response.push_back(nums[i]*nums[i]);
                i++;
            }
            else{
                response.push_back(nums[j]*nums[j]);
                j--;
            }
        }
        reverse(response.begin(),response.end());
        return response;
    }
};