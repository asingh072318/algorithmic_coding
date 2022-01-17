## https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(),i=0;
        vector<bool> canVisit(n,false);
        canVisit[0]=true;
        while(i<n){
            if(canVisit[i]){
                for(int j=i;j<n && j<=i+nums[i];j++){
                    canVisit[j]=true;
                    if(canVisit[n-1])
                        return true;
                }
            }
            i++;
        }
        if(canVisit[n-1])
            return true;
        return false;
    }
};