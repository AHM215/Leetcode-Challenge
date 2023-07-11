class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0)); // Initialize a m+1 x n+1 2D vector with 0s
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1]; // If the characters match, add 1 to the previous diagonal element
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // If the characters don't match, take the max of the previous row and column elements
                }
            }
        }
        
        return dp[m][n]; // Return the last element of the 2D vector, which holds the length of the longest common subsequence
    }
};