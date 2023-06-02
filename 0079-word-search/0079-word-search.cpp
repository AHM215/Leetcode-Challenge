/*// 
Time complexity: O(M*N*4^L), where M is the number of rows, N is the number of columns,and L is the length of the target word.
Space complexity: O(L), where L is the length of the target word. This is the maximum 
depth of the recursion stack that we can reach.
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        // Iterate over each cell of the board
        for (unsigned int i = 0; i < board.size(); i++) {
            for (unsigned int j = 0; j < board[0].size(); j++) {
                // If a path exists that forms the target word, return true
                if (dfs(board, i, j, word)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
        // If the target word has been fully formed, return true
        if (!word.size()) {
            return true;
        }
        // If the cell is out of bounds or does not match the current character of the target word, return false
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0]) {
            return false;
        }
        // Mark the current cell as visited
        char c = board[i][j];
        board[i][j] = '*';
        // Recursively search the neighboring cells for the remaining characters of the target word
        string s = word.substr(1);
        bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
        // Restore the state of the cell
        board[i][j] = c;
        return ret;
    }
};