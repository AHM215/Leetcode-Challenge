//Using Backtracking

/*Tree explain (include the i-th or Not)
              []
          /         \
       [1]           []
      /    \       /    \
  [1,2]  [1]     [2]     []
   /  \   / \    /   \    / \
[1,2,3][1,2][1][1,3] [2,3][2][3][ ]
*/
class Solution {
public:
    vector<vector<int>> ans;  // To store all possible subsets
    
    void sub(vector<int> &nums, int i, vector<int> temp)
    {
        if(i == nums.size())  // Base case: reached end of nums
        {
            ans.push_back(temp);  // Add current subset to the result
            return;
        }
        temp.push_back(nums[i]);  // Include nums[i] in the current subset
        sub(nums, i + 1, temp);  // Recurse on the rest of the array, with i+1 and updated subset (Include nums[i])
        temp.pop_back();  // Backtrack by removing nums[i] from the current subset
        sub(nums, i + 1, temp);  // Recurse again,with i+1 and the same subset (excluding nums[i])

    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;      
        sub(nums, 0, temp);
        return ans;
    }
};