class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        if (total_sum % 2 == 1) {
            return false;
        }
        total_sum /= 2;
        vector<bool> dp(total_sum + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = total_sum; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[total_sum];
    }
};