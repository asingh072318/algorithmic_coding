## https://leetcode.com/problems/delete-and-earn/
class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		vector<int> count(10002);
		for(int i=0;i<nums.size();i++)
		{
			count[nums[i]]+=nums[i];
		}
		vector<int> response(10002,-1);
		response[1]=count[1];
		response[2]=max(count[1],count[2]);
		for(int i=3;i<response.size();i++)
		{
			response[i]=max(response[i-2]+count[i],response[i-1]);
		}
		return max(response[10000],response[9999]);
	}
};