## https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> front,back;
        int prod = 1;
        for(int i=0;i<nums.size();i++){
            prod = prod*nums[i];
            front.push_back(prod);
        }
        prod = 1;
        for(int i=nums.size()-1;i>=0;i--){
            prod = prod*nums[i];
            back.push_back(prod);
        }
        reverse(back.begin(),back.end());
        vector<int> response;
        response.push_back(back[1]);
        for(int i=1;i<nums.size()-1;i++){
            response.push_back(front[i-1]*back[i+1]);
        }
        response.push_back(front[nums.size()-2]);
        return response;
    }
};