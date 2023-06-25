class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minProduct = 1;     // Initialize the minimum product to 1
        int maxProduct = 1;     // Initialize the maximum product to 1
        int ans = INT_MIN;      // Initialize the answer to the smallest possible integer
        for(int i=0; i<n; i++){
            if(nums[i] < 0){    // If the current element is negative, swap the minimum and maximum products
                swap(maxProduct, minProduct);
            }
            // Update the maximum and minimum products ending at the current index
            maxProduct = max(maxProduct*nums[i], nums[i]);
            minProduct = min(minProduct*nums[i], nums[i]);
            ans = max(ans, maxProduct);     // Update the answer with the maximum product seen so far
        }
        return ans;     // Return the maximum product of a subarray in the input array
    }
};