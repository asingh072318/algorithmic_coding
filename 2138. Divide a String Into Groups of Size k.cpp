## https://leetcode.com/contest/weekly-contest-276/problems/divide-a-string-into-groups-of-size-k/
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> response;
        int n = s.size();
        for(int i=0;i<n;i+=k){
            if(i+k>n){
                int count = k-n+i;
                string str = s.substr(i,n-i);
                while(count--){
                    str+=fill;
                }
                response.push_back(str);
            }
            else{
                response.push_back(s.substr(i,k));
            }
        }
        return response;
    }
};