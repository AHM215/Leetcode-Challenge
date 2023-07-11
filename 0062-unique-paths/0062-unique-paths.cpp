class Solution {
private:
    int solve(int m, int n,int a, int b, vector<vector<int>> &dp)
    {
        //cheking if the value is previously stored in DP array
        if(dp[m][n]!=-1)return dp[m][n];

        //base case
        //if the recurrsion reached the bottom or right edge then only one path is present to the final box
        if(m==a || n==b)return 1;

        //adding and storing the number of paths of right and bottom cell
        dp[m][n] = solve(m+1,n,a,b, dp)+solve(m, n+1,a,b,dp);
        
        return dp[m][n];
    }

    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0,0,m-1,n-1, dp);
    }
};