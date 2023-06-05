class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        dfs(s, 0, ans);
        return ans;
    }
    
private:
    void dfs(string& s, int pos, vector<string>& ans) {
        if (pos == s.length()) {
            ans.push_back(s);
            return;
        }
        
        if (isalpha(s[pos])) {
            s[pos] ^= (1 << 5);  // toggle case
            dfs(s, pos + 1, ans);
            s[pos] ^= (1 << 5);  // toggle case back
        }
        dfs(s, pos + 1, ans);
    }
};