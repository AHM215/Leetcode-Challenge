class Solution {
private:
    bool isPalindromic(vector<vector<bool>> &dp, int i, int j, string &s){
        // Check if the substring from i to j is a palindrome
        if(i == j)
            return dp[i][j]= true; // Base case: a single character is always a palindrome
        if(j-i == 1){
            if(s[i] == s[j])
                return dp[i][j] = true; // Base case: two adjacent characters are a palindrome if they are the same
            else
                return dp[i][j] = false;
        }
        if(s[i] == s[j] && dp[i+1][j-1] == true)
            return dp[i][j] = true; // A substring is a palindrome if its first and last characters are the same, and its interior is also a palindrome
         else
            return dp[i][j] = false;
    }
public:
    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        // Initialize a 2D boolean array to store whether substrings are palindromic
        vector<vector<bool>> dp(n,vector<bool>(n, false));
        for(int g=0;g<n;g++){
            // Iterate over all substrings of length g+1
            for(int i=0,j=g;j<n;i++,j++){
                isPalindromic(dp,i,j,s);
                // If the current substring is a palindrome and its length is greater than the current maximum length, update the maximum length and starting index
                if(dp[i][j] == true){    
                        count++;
                }
            }
        }
        // Return the longest palindromic substring
        return count;  
    }
};