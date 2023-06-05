class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans; 
        dfs(s, 0, ans);     
        return ans;       
    }
    
private:
    void dfs(string& s, int pos, vector<string>& ans) {
        if (pos == s.length()) {    // Base case
            ans.push_back(s);      
            return;              
        }
        
        if (isalpha(s[pos])) {      // If the current character is a letter
            s[pos] ^= (1 << 5);     // Toggle the case of the letter by XORing with 1 << 5
            dfs(s, pos + 1, ans);   // Recursively generate permutations with the modified string
            s[pos] ^= (1 << 5);     // Toggle the case back to its original state
        }
        
        dfs(s, pos + 1, ans);       // Recursively generate permutations without modifying the current character
    }
};

/*
Time complexity: O(n * 2^n), since we need to generate 2^n permutations, and for each permutation, we need to iterate through the entire string of length n to check which characters are letters.

Space complexity: O(n * 2^n), where n is the length of the input string. This is because we generate 2^n permutations, and each permutation can be up to length n.
*/