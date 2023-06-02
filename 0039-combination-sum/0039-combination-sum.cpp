/* Using Backtracking 
explain: search untill the target==0 
                                        {[], 7}
                          /           |           |           \
                         2            3           6            7
                   /     \       /     \      /     \        |
                  2       3     3       -     6       -       7
                /   \    / \     |               |        /   \
               2     -  2   -    -               -       -     -
              / \        |                              |
             -   -       -                              -
search([2, 3, 6, 7], 5, 0, [2])
search([2, 3, 6, 7], 3, 0, [2,2])
search([2, 3, 6, 7], 0, 1, [2,2,3])
*/

class Solution {
private:
    // function to search for combinations
    void search(vector<int>& num, int target, int next, vector<int>& pSol) {
        if (target == 0) { // if the target sum is reached, add the partial solution to the result
            result.push_back(pSol);
            return;
        }
        if (next == num.size() || target - num[next] < 0) { // if there are no more elements or the target sum is exceeded, return
            return;
        }
        pSol.push_back(num[next]); // include the current element in the partial solution
        // search for combinations that include the current element
        search(num, target - num[next], next, pSol);
        pSol.pop_back(); // remove the current element from the partial solution
        // search for combinations that exclude the current element
        search(num, target, next + 1, pSol);
    }
public:
    vector<vector<int> > result; // vector to store the results
    
    vector<vector<int> > combinationSum(vector<int> &num, int target) {
        sort(num.begin(), num.end()); //  Sorting the input array can help to eliminate duplicate combinations and improve the efficiency of the search algorithm.
        vector<int> pSol;
        search(num, target, 0, pSol);
        return result;
    }  
};