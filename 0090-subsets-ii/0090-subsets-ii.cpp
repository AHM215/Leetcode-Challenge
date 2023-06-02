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
    vector<vector<int>> ans;
    void sub(vector<int> &nums, int i, vector<int> temp)
    {

        if(i==nums.size())
        {
            bool isPresent = find(ans.begin(), ans.end(), temp) != ans.end();
            if(!isPresent){
                ans.push_back(temp);
                return;
            }
            return;
        }
        temp.push_back(nums[i]);
        sub(nums,i+1,temp);
        temp.pop_back();
        sub(nums,i+1,temp);

    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp; 
        sort(nums.begin(),nums.end());
        sub(nums, 0, temp);
        return ans;
    }
};