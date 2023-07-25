// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         bool flag = false;
//         for(int i =0;i<nums.size()-1;i++){
//             if(nums[i] == nums[i+1]) return true;
//         }
//         return flag;
//     }
// };

// solve with map
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++) {
            if (count[nums[i]] > 0) {
                return true;
            }
            count[nums[i]]++;
        }
        return false;
    }
};