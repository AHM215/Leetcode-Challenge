class Solution {
    int l;
    int dp[103];
public:
    int recurse(int index,vector<int>& a)
    {
        if(index>=l )
            return 0;
        if(dp[index]>-1)
            return dp[index];
        
        int donothing= recurse(index+1,a);
        int dosomething= a[index]+recurse(index+2, a);
        return dp[index]=max(donothing, dosomething);
    }
    int rob(vector<int>& nums){
        if(nums.size()==1)
           return nums[0];
        
        memset(dp,-1,sizeof(dp));
        l= nums.size()-1;
        int maxvalue=0;
        maxvalue= max(maxvalue, recurse(0,nums));
        memset(dp,-1, sizeof(dp));
        l=nums.size();
        maxvalue= max(maxvalue, recurse(1,nums));
        return maxvalue;
    }
    
   /*int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    
    // Compute the maximum amount of money that can be robbed starting from the first house but not the last house
    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    int curr = prev1;
    for(int i = 2; i < n-1; i++){
        curr = max(prev1, nums[i] + prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    int max1 = curr;
    
    // Compute the maximum amount of money that can be robbed starting from the last house but not the first house
    prev2 = nums[1];
    prev1 = max(nums[1], nums[2]);
    curr = prev1;
    for(int i = 3; i < n; i++){
        curr = max(prev1, nums[i] + prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    int max2 = curr;
    
    return max(max1, max2);
}*/
};