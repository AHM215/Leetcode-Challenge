/*
s:   a p p l e p e n a p p l e
dp:  T F F F F T F F T F T F T
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Convert the wordDict vector to a set for faster word lookup.
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());

        // Create a boolean vector dp of size n+1, where n is the length of s.
        vector<bool> dp(s.length() + 1);

        // Initialize dp[0] to true.
        dp[0] = true;

        // Loop over each character i in s, and compute dp[i] based on the values of dp[j]
        // for all j < i.
        for(int i=1; i <= s.length(); i++){
            for(int j=0; j < i; j++){
                // If dp[j] is true, and the substring s[j:i-j] is a word in the dictionary,
                // set dp[i] to true and break out of the inner loop.
                if(dp[j] && word_set.find(s.substr(j, i-j)) != word_set.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};