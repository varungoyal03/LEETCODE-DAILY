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
    int sum=0;

    int dfs(TreeNode* root){
        if(!root) return 0;

      int l=  dfs(root->left);
      int r= dfs(root->right);
      sum+=abs(l-r);
      return root->val+l+r;

    }
public:
    int findTilt(TreeNode* root) {
dfs(root);
    return sum;    
    }
};