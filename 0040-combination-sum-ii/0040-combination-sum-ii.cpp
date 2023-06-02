class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector <vector <int>> ans;
        vector <int> v;
        solution(0,target,candidates,ans,v);
        return ans;
    }
    void solution(int i,int target,vector <int> &candidates,vector <vector <int>> &ans,vector <int> &v){
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int index=i;index<candidates.size();index++){
            if(index>i && candidates[index]==candidates[index-1]) continue;
            if(candidates[index]>target) break;
            v.push_back(candidates[index]);
            solution(index+1,target-candidates[index],candidates,ans,v);
            v.pop_back();
        }
    }
};