## https://leetcode.com/problems/n-th-tribonacci-number/
class Solution {
public:
    int tribonacci(int n) {
        vector<int> f(n+1,0);
        if(n>0)
            f[1]=1;
        if(n>1)
            f[2]=1;
        for(auto i=3;i<n+1;i++)
            f[i]=f[i-1]+f[i-2]+f[i-3];
        return f[n];
    }
};