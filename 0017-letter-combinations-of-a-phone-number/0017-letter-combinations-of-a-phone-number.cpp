/*
                ""
              / | \
            a   b   c
           /|\ /|\ /|\
          d e f d e f d e f
*/
class Solution {
private:
    void letterCombinations(string digits, vector<string>& output, string &temp, vector<string>& pad, int index){
        // Base case
        if(index == digits.size()){
            output.push_back(temp);
            return;
        }
        // Recursive case
        string value = pad[digits[index]-'0'];
        for(int i=0; i<value.size(); i++){
            temp.push_back(value[i]);
            letterCombinations(digits, output, temp, pad, index+1);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        // Map each digit to its corresponding letters
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> output;
        string temp;
        // Recursively generate all possible combinations of letters based on the input string
        letterCombinations(digits, output, temp, pad, 0);
        return output;
    }
};

/* 
Time complexity: O(3^n * 4^m), where n is the number of digits that correspond to 3 letters (2, 3, 4, 5, 6, 8) and m is the number of digits that correspond to 4 letters (7, 9). 
The time complexity is due to the fact that we need to generate all possible combinations of letters, which takes O(3^n * 4^m) time in the worst case. 
The space complexity is also O(3^n * 4^m)
The worst case is when all digits correspond to 4 letters, in which case the recursion depth is equal to the length of the input string.
*/