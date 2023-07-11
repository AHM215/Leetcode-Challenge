class Solution {
public:
    /*// Time complexity: O(n)
    // Space complexity: O(n)
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1); // initialize dp array with -1
        // return the maximum amount of money that can be robbed starting from the first house
        return rec(nums, 0, dp);
    }

    // memoized recursive function to compute the maximum amount of money that can be robbed starting from the current index
    int rec(vector<int>& nums, int idx, vector<int>& dp){
        // Base Case
        if(idx >= nums.size()) return 0;
        // Check if answer already exists in dp array
        if(dp[idx] != -1) return dp[idx];
        // Compute maximum amount of money that can be robbed starting from the current index and store it in dp array
        dp[idx] = max(rec(nums,idx+1,dp),nums[idx]+rec(nums,idx+2,dp));
        // Return the maximum amount of money that can be robbed starting from the current index
        return dp[idx];
    }*/
    
    // Time complexity: O(n)
    // Space complexity: O(1)
    int rob(vector<int>& nums){
            int n = nums.size();
            if (n == 0) return 0;
            if (n == 1) return nums[0];

            // Initialize the dp array
            vector<int> dp(n+1, 0);
            dp[1] = nums[0];

            // Fill the dp array using the recurrence relation
            for (int i = 2; i <= n; i++) {
                dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
            }

            return dp[n];
        }   // return the maximum amount of money that can be robbed from the input array
};
