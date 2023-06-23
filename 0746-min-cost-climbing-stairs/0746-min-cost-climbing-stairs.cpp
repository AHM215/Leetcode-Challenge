class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(n)
    // memoization approach
    /*int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1); // initialize dp array with -1
        // return the minimum cost of climbing to the top using memoized functions
        return min(fun(cost, n-1, dp), fun(cost, n-2, dp));
    }
    
    // memoized recursive function to compute the minimum cost of climbing to the nth step
    int fun(vector<int>& cost, int n, vector<int>& dp){
        // Base Case
        if(n<0)return 0;
        if(n==0 || n==1 ) return cost[n];
        
        // Check if answer already exists in dp array
        if(dp[n] != -1) return dp[n];
        
        // Compute minimum cost of climbing to nth step and store it in dp array
        dp[n] = cost[n] + min(fun(cost, n-1, dp), fun(cost, n-2, dp));
        
        // Return the minimum cost of climbing to nth step
        return dp[n];
    }*/
    // dp approach
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0); // initialize dp array
        
        // compute the minimum cost for each step
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        
        // return the minimum cost to climb to the top
        return dp[n];
    }
    
};