## https://leetcode.com/problems/array-of-doubled-pairs/
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> mp;
        sort(arr.begin(),arr.end());
        int nonNegativeIndex=-1;
        for(int i=0;i<arr.size();i++){
            if(i!=arr.size()-1 && arr[i]<0 && arr[i+1] >= 0)
                nonNegativeIndex = i+1;
            mp[arr[i]]++;
        }
        if(nonNegativeIndex!=-1)
            reverse(arr.begin(),arr.begin()+nonNegativeIndex);
        if(arr[0]<0 && nonNegativeIndex == -1)
            reverse(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]]>0){
                mp[arr[i]]--;
                if(mp[2*arr[i]]>0)
                    mp[2*arr[i]]--;
                else
                    return false;
            }
        }
        return true;
    }
};