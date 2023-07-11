class Solution {
private:
//     int solve(int m, int n,int a, int b, vector<vector<int>> &dp)
//     {
//         //cheking if the value is previously stored in DP array
//         if(dp[m][n]!=-1)return dp[m][n];

//         //base case
//         //if the recurrsion reached the bottom or right edge then only one path is present to the final box
//         if(m==a || n==b)return 1;

//         //adding and storing the number of paths of right and bottom cell
//         dp[m][n] = solve(m+1,n,a,b, dp)+solve(m, n+1,a,b,dp);
        
//         return dp[m][n];
//     }

    
public:
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     return solve(0,0,m-1,n-1, dp);
    // }
    int uniquePaths(int m, int n) {
        //dp[i][j] stores the number of ways to reach the cell (i,j)
        vector<vector<int>> dp(m, vector<int>(n, 0));

        //initializing the first row and column
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;

        //filling the DP table in bottom-up manner
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        //returning the answer
        return dp[m - 1][n - 1];
    }
};