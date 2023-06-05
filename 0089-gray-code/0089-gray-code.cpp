class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        search(n, result);
        return result;
    }

private:
    void search(int n, vector<int>& result) {
        if (n == 0) {
            result.push_back(0);
        } else {
            search(n - 1, result);
            int size = result.size();
            for (int i = size - 1; i >= 0; i--) {
                int num = result[i] + (1 << (n - 1));
                result.push_back(num);
            }
        }
    }
};