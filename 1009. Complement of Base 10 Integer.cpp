## https://leetcode.com/problems/complement-of-base-10-integer/
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        int n2=n,count=0;
        while(n2){
            n2>>=1;
            count++;
        }
        return n^((int)(pow(2,count)-1));
    }
};