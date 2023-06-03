/* 
Time complexity: O(n * 2^n), where n is the length of the input string. 
Space complexity: O(n * 2^n), which is the space required to store all possible partitions. 
The worst case is when the input string contains all distinct characters, in which case there are 2^n possible partitions.
*/
// Backtracking Approach 
class Solution {
private:
    // Check if a substring is a palindrome
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    
    void search(string& s, int start, vector<string>& par, vector<vector<string>>& pars){
        // Base case
        if (start == s.size()) {
            pars.push_back(par);
            return;    
        }
        // Recursive case: try all possible substrings starting from the current index
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                par.push_back(s.substr(start, i - start + 1));
                search(s, i + 1, par, pars);
                par.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> pars;
        vector<string> par;
        
        // Call the recursive search function with the starting index set to 0 and an empty partition vector
        search(s, 0, par, pars);
        
        return pars;
    }
};

