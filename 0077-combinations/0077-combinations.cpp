class Solution {
private:
    vector<vector<int>> res;
    void search(int n, int k, vector<int> presult, int index){
        if(presult.size()==k){
            res.push_back(presult);
            return;
        }
        for(int i=index;i<n;i++){
            presult.push_back(i+1);
            search(n, k, presult, i+1);
            presult.pop_back();
        }
        
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> presult;
        search(n, k, presult, 0);
        return res;
    }
};