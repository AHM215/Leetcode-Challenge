class Solution {
public:
    vector<string> letterCasePermutation(const string& s) {
        vector<string> ans;
        dfs(s, 0, ans);
        return ans;
    }
    
private:
    void dfs(const string& s, unsigned short pos, vector<string>& ans) {
        if (pos == s.length()) {
            ans.push_back(s);
            return;
        }
        
        dfs(s, pos + 1, ans);
        if (isalpha(s[pos])) {
            string t(s);
            t[pos] ^= (1 << 5);  // toggle case
            dfs(t, pos + 1, ans);
        }
    }
};