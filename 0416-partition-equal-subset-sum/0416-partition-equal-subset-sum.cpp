class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        // If the total sum is odd, we can't partition the array into two
        // subsets with equal sums, so return false.
        if (total_sum % 2 == 1) {
            return false;
        }
        
        // Divide the total sum by 2 to get the target sum for each subset.
        total_sum /= 2;
        
        // Initialize the dynamic programming array with dp[0] = true,
        // because it's always possible to create a subset of nums with sum 0.
        vector<bool> dp(total_sum + 1, false);
        dp[0] = true;
        
        // Iterate over each element of nums and update the dp array.
        for (int i = 0; i < n; i++) {
            // Iterate over the dp array in reverse order to ensure that
            // all previous values of dp are taken into account.
            for (int j = total_sum; j >= nums[i]; j--) {
                // Update dp[j] to true if either dp[j] or dp[j-nums[i]] is true,
                // because we can create a subset of nums with sum j either by
                // including nums[i] or not including nums[i].
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        
        // Return the value of dp[total_sum], which indicates whether it's
        // possible to create a subset of nums with sum equal to total_sum.
        return dp[total_sum];
    }
};