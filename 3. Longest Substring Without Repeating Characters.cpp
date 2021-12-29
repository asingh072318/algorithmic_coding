## https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        map<char,int> mp;
        int i,size = s.size(),start=0,end=0,maxlen=INT_MIN;
        for(i=0;i<size;i++){
            if(mp[s[i]]!=0){
                 while(mp[s[i]]!=0){
                    mp[s[start]]--;
                    start++;
                }
            }
            mp[s[i]]++;
            end = i;
            maxlen = max(maxlen,end-start+1);
        }
        return maxlen;
    }
};