/* Backtracking 
             [1, 2, 3]
         /      |      \
   [2, 1, 3] [3, 2, 1] [1, 3, 2]
   /    \    /     \    /     \
[3, 1, 2] [1, 3, 2] [2, 3, 1] [3, 2, 1] [2, 1, 3] [1, 2, 3]
*/

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index){
        if(index == nums.size()){ // Base case
            ans.push_back(nums);
            return;
        }
        // Generate all possible permutations by swapping each element with all subsequent elements
        for(int j=index; j<nums.size(); j++){
            swap(nums[index], nums[j]);
            solve(nums, ans, index+1);
            swap(nums[index], nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
        solve(nums,ans,index);
        return ans;
    }
};