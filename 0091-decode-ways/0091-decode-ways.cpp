class Solution {
public:
    int numDecodings(string s) {
        int n = s.length(); // get the length of the input string
        vector<int> dp(n+1); // create a vector to store the DP values
        dp[0] = 1; // set the base case dp[0] to 1
        dp[1] = s[0] != '0' ? 1 : 0; // set the base case dp[1] based on the first digit of s
        for (int i = 2; i <= n; i++) { // loop over all indices of the input string
            if (s[i-1] != '0') { // if the current digit is not zero
                dp[i] += dp[i-1]; // add the previous DP value
            }
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')) { // if the current and previous digits form a valid two-digit code
                dp[i] += dp[i-2]; // add the DP value two indices back
            }
        }
        return dp[n]; // return the final DP value
    }
};