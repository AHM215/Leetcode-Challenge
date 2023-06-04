/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return solution2(root);
    }
    int solution1(TreeNode* root){
        //dfs
        if(!root)
            return NULL;
        return 1+max(solution1(root->left),solution1(root->right));
    }
    int solution2(TreeNode* root){
        if(!root)
            return 0;
        queue<TreeNode*> q;
        int depth=0;
        q.push(root);
        while(!q.empty()){
            depth++;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return depth;
    }
    
};