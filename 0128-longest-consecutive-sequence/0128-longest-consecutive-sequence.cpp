class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        int count =1;
        int maxs=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1]){    
                if(abs(nums[i]-nums[i-1])==1)
                    count+=1;
                else{
                    maxs=max(maxs,count);
                    count=1;
                }
            }
            
        }
        return max(maxs,count);
    }
};