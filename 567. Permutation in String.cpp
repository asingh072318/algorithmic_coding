## https://leetcode.com/problems/permutation-in-string/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> c1(26,0),c2(26,0);
        int i;
        for(i=0;i<s1.size();i++){
            c1[s1[i]-'a']++;
            c2[s2[i]-'a']++;
        }
        if(c1==c2) return true;
        int start = 0, end = i;
        while(end<s2.size()){
            c2[s2[start]-'a']--;
            c2[s2[end]-'a']++;
            if(c1==c2) return true;
            start++;
            end++;
        }
        return false;
    }
};