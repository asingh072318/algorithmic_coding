## https://leetcode.com/problems/number-complement/
class Solution {
public:
    int findComplement(int num) {
        int count = 0,n2=num;
        while(n2!=0){
            n2=n2>>1;
            count++;
        }
        return num^((int)(pow(2,count)-1));
    }
};