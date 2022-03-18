## https://leetcode.com/problems/majority-element-ii/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1=-1,cand2=-1,v1=0,v2=0,n=nums.size();
        vector<int> response;
        for(int i=0;i<n;i++){
            if(nums[i]==cand1)
                v1++;
            else if(nums[i]==cand2)
                v2++;
            else if(v1 == 0){
                cand1=nums[i];
                v1=1;
            }
            else if(v2 == 0){
                cand2=nums[i];
                v2=1;
            }
            else{
                v1--;
                v2--;
            }
        }
        v1=0,v2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==cand1)
                v1++;
            else if(nums[i]==cand2)
                v2++;
        }
        if(v1>n/3)
            response.push_back(cand1);
        if(v2>n/3)
            response.push_back(cand2);
        return response;
    }
};