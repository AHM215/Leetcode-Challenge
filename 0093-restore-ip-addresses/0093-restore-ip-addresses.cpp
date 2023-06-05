class Solution {
private:
    vector<string> res;

    void backtrack(int i, int dots, string curIP, string s) {
        // Base case: we have generated 4 segments and processed all characters
        if (dots == 4 && i == s.length()) {
            // Add the current IP address to the result vector
            res.push_back(curIP.substr(0, curIP.length() - 1)); // remove the last dot
            return;
        }
        // If we have generated more than 4 segments or processed all characters,
        // we cannot generate a valid IP address, so return
        if (dots > 4)
            return;
        
        // Try adding 1 to 3 characters to the current segment
        for (int j = i; j < min(i + 3, (int)s.length()); j++) {
            // Check if the current segment is valid (less than 256 and does not start with 0)
            string seg = s.substr(i, j - i + 1);
            if (stoi(seg) < 256 && (seg.length() == 1 || seg[0] != '0')) {
                // If the current segment is valid, add it to the current IP address
                // and recursively generate the next segment
                backtrack(j + 1, dots + 1, curIP + seg + ".", s);
            }
        }
    };

public:
    vector<string> restoreIpAddresses(string s) {
        // If the input string is longer than 12 characters, it cannot form a valid IP address,
        // so return an empty vector
        if (s.length() > 12)
            return res;
        // Generate all valid IP addresses starting from the first segment
        backtrack(0, 0, "", s);
        return res;
    }
};