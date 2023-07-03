class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<vector<int>> ans;
       for(int i=0;i<nums.size();i++)
       {
           int target=-nums[i];
           int l=i+1;
           int r=nums.size()-1;
           while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;

           while(l<r)
           {
               if(nums[l]+nums[r]>target) r--;
               else if(nums[l]+nums[r]<target) l++;
               else{
                   vector<int> res = {nums[i], nums[l], nums[r]};
                   ans.push_back(res);
                   while (l < r && nums[l] == res[1]) l++;
                   while (l < r && nums[r] == res[2]) r--;
                   }
            }
            
        }   

        return ans;
       }
    };
