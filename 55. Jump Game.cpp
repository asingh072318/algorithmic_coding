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

## Another Solution(Greedy)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(),goal = n-1;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=goal)
                goal = i;
        }
        return goal==0;
    }
};