//Using tabulation method+space optimization
class Solution {
public:
   
    int climbStairs(int n) {
        int prev=1;
        int prev2=0;
        for(int i=1;i<=n;i++){
            int curr= prev+prev2;
            prev2=prev;
            prev=curr;
           
        }
        return prev;
       }
       
    
};