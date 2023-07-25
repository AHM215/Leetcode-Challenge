class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            frq[nums[i]]++;
        }
        vector<int> count;
        for(auto it=frq.begin();it != frq.end();it++)
        {
            //cout<<it->first;
            count.push_back(it->second);
        }
        sort(count.begin(),count.end());
        reverse(count.begin(),count.end());
        int a=0;
        while(ans.size()!=k)
        {
           for(auto it=frq.begin();it != frq.end();it++)
            {
               if(it->second == count[a] && a < k){
                    ans.push_back(it->first);
                    a++;
                }
             
            }
            
        }
        return ans;
    }
};