//Using tabulation method
class Solution {
public:
   
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
       dp[0]={1};
       int ss=0;
       for(int i=1;i<=n;i++){
        int fs=dp[i-1];
       if(i>1)  ss=dp[i-2];
       dp[i]=fs+ss;
       }
       return dp[n];
    }
};