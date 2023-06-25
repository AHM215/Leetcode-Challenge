class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX); // initialize DP array with maximum values
        dp[0] = 0; // base case: it takes 0 coins to make 0 amount
        sort(coins.rbegin(), coins.rend());
        for (int i = 1; i <= amount; i++) { // loop over all amounts from 1 to amount
            for (int j = 0; j < coins.size(); j++) { // loop over all coin denominations
                // if the current coin can be used to make up the current amount
                // and using the current coin leads to a valid solution
                if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1); 
                    // take the minimum of the current DP value and the new DP value
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount]; // return the final DP value
    }
};