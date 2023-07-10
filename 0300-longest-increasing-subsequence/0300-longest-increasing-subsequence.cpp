/*
DP: [1, 1, 1, 2, 2, 3, 4, 4]
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1); // Initialize all elements to 1 (minimum length of a subsequence is 1)
    int max_len = 1; // Initialize the maximum length to 1
    
    for(int i=1; i < n; i++){
        for(int j=0; j < i; j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j]+1); // Update dp[i] to the length of the longest subsequence ending at i
            }
        }
        max_len = max(max_len, dp[i]); // Update the maximum length seen so far
    }
    
    return max_len;
}
};