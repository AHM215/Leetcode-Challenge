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
        if(n == 1) return nums[0];

        int prev2 = nums[0];   // initialize prev2 to the value of the first element
        int prev1 = max(nums[0], nums[1]); // initialize prev1 to the maximum of the first two elements
        int curr = prev1;      // initialize curr to the maximum of prev2 and prev1

        for(int i = 2; i < n; i++){
            curr = max(prev1, nums[i] + prev2); 
            // update curr to the maximum of prev1 and the sum of the current element and prev2
            prev2 = prev1;  // update prev2 to the previous value of prev1
            prev1 = curr;   // update prev1 to the current value of curr
        }

        return curr;    // return the maximum amount of money that can be robbed from the input array
    }
};
