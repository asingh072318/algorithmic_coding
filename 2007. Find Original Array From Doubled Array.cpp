## https://leetcode.com/problems/find-original-array-from-doubled-array/
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> response,empty;
        unordered_map<int,int> mp;
        if(changed.size()%2 != 0)
            return empty;
        else{
            sort(changed.begin(),changed.end());
            for(int i=0;i<changed.size();i++){
                mp[changed[i]]++;
            }
            for(int i=0;i<changed.size();i++){
                if(mp[changed[i]]>0){
                    mp[changed[i]]--;
                    if(mp[2*changed[i]]>0){
                        mp[2*changed[i]]--;
                        response.push_back(changed[i]);
                    }
                    else
                        return empty;
                }
            }
        }
        return response;
    }
};