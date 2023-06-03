/*
                    []
             /               \
        [4]                   []
       /    \              /    \
    [4,6]  [4,7]         [6]    [7]
     /  \     |        /   \     |
[4,6,7] [4,6,7,7]  [6,7] [6,7,7] [7,7]
*/
class Solution {
private:
    set<vector<int>> ans;

    void search(vector<int>& nums, vector<int> presult, int index){
        if(index == nums.size()){ 
            if(presult.size() > 1)
                ans.insert(presult);
            return;
        }
        if(presult.empty() || nums[index] >= presult.back()){ 
            presult.push_back(nums[index]); // add nums[index] to presult
            search(nums, presult, index+1); // recursively search
            presult.pop_back(); // remove nums[index] from presult
        }
        search(nums, presult, index+1); // recursively search for subsequences starting from the next index
    }
    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums){
        vector<int> presult;
        search(nums, presult, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
/*
Time complexity: O(2^N * N), where N is the length of the input array.
Space complexit: O(2^N * N)
*/