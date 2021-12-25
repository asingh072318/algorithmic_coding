## https://leetcode.com/problems/two-furthest-houses-with-different-colors/
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int fcolor = colors[0];
        int maxd = -1;
        for(int i=colors.size()-1;i>0;i--){
            if(colors[i]!=fcolor){
                maxd=i;
                break;
            }
        }
        for(int i=1;i<colors.size();i++){
            if(colors[i]!=fcolor){
                fcolor=i;
                break;
            }
        }
        for(int i=colors.size()-1;i>0;i--){
            if(colors[i]!=colors[fcolor]){
                maxd=max(maxd,i-fcolor);
                break;
            }
        }
        return maxd;
    }
};