## https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    static bool mycmp(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> response;
        sort(intervals.begin(),intervals.end(),mycmp);
        vector<int> currInterval{intervals[0][0],intervals[0][1]};
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=currInterval[0] && intervals[i][1]>currInterval[1]){
                currInterval[0] = intervals[i][0];
                currInterval[1] = intervals[i][1];
            }
            else if(intervals[i][0]<=currInterval[1] && intervals[i][1]>currInterval[1]){
                currInterval[1] = intervals[i][1];
            }
            else if(intervals[i][0] >currInterval[1] && intervals[i][1]<currInterval[1]){
                continue;
            }
            else if(intervals[i][0] >currInterval[1]){
                response.push_back(currInterval);
                currInterval[0] = intervals[i][0];
                currInterval[1] = intervals[i][1];
            }
        }
        response.push_back(currInterval);
        return response;
    }
};