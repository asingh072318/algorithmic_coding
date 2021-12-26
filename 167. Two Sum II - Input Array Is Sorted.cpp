## https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> response;
        int index1 = 0,index2 = numbers.size()-1;
        while(numbers[index1]+numbers[index2] != target){
            if(numbers[index1]+numbers[index2] < target)
                index1++;
            else if(numbers[index1]+numbers[index2] > target)
                index2--;
        }
        response.push_back(index1+1);
        response.push_back(index2+1);
        return response;
    }
};