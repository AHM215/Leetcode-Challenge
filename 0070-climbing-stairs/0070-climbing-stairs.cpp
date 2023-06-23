/*
         dp[3]
        /     \
      dp[2]   dp[1]
     /    \
  dp[1]  dp[0]
*/

class Solution {
public:
    // memoization approach
    int findWays(int n, vector<int>& dp) {
        // base cases
        if (n <= 1) {
            return 1;
        }
        // check if the result for n has already been computed
        if (dp[n] != -1) {
            return dp[n];
        }
        // compute the result recursively and store it in the dp array
        dp[n] = findWays(n-1, dp) + findWays(n-2, dp);
        return dp[n];
    }
    
    int climbStairs(int n) {
        // initialize dp array with -1
        vector<int> dp(n+1, -1);
        // call the helper function to compute the result
        return findWays(n, dp);
    }

    /* dynamic programming approach
    int climbStairs(int n) {
        // initialize dp array with base cases
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        // compute the rest of the results using a loop
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        // return the final result
        return dp[n];
    }
    */
};