## https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(),i=0;
        vector<int> minsteps(n,INT_MAX);
        minsteps[0] = 0;
        while(i<n){
            if(minsteps[i]!=INT_MAX){
                for(int j=i+1;j<n&&j<=i+nums[i];j++){
                    minsteps[j]=min(minsteps[j],minsteps[i]+1);
                    if(minsteps[n-1]!=INT_MAX)
                        return minsteps[n-1];
                }
            }
            i++;
        }
        return minsteps[n-1];
    }
};