class Solution {
private:
    vector<vector<int>> res;
    void search(int n, int k, vector<int> presult, int index){
        if(presult.size()==k){ // Base case
            res.push_back(presult); 
            return;
        }
        for(int i=index;i<n;i++){ 
            presult.push_back(i+1); // add the current element to the combination
            search(n, k, presult, i+1); // recursively call the function with the next index
            presult.pop_back(); // remove the current element from the combination
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> presult; 
        search(n, k, presult, 0); 
        return res;
    }
};