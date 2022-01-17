## https://leetcode.com/contest/weekly-contest-276/problems/minimum-moves-to-reach-target-score/
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int i=0;
        while(target!=1){
            if(target%2!=0){
                target--;
                i++;
            }
            if(maxDoubles){
                target=target/2;
                i++;
                maxDoubles--;
            }
            else{
                i=i+target-1;
                target=1;
            }
        }
        return i;
    }
};