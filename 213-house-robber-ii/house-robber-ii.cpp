class Solution {
public:
    int helper(vector<int>& nums, int idx, int n, vector<int>& dp){
        if(idx > n) return 0;

        if(dp[idx] != -1) return dp[idx];

        int pick = nums[idx] + helper(nums, idx+2, n, dp);
        int notpick = helper(nums, idx+1, n, dp);

        return dp[idx] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int first = helper(nums, 0, n-2, dp1);  // 0 → n-2
        int second = helper(nums, 1, n-1, dp2); // 1 → n-1

        return max(first, second);
    }
};