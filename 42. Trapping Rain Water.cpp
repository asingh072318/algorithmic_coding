## https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1,maxLeft=0,maxRight=0,result=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>maxLeft) maxLeft = height[left];
                else result+=maxLeft-height[left];
                left++;
            }
            else{
                if(height[right]>maxRight) maxRight = height[right];
                else result+=maxRight-height[right];
                right--;
            }
        }
        return result;
    }
};