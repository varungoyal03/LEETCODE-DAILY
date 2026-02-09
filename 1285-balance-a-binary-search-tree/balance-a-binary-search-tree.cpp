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
  vector<int> vals;
   void inorder(TreeNode* node) {
        if(!node) return;
        inorder(node->left);
        vals.push_back(node->val);
        inorder(node->right);
    }
       TreeNode* build(int left,int right) {
        if(left>right) return NULL;

        int mid=(left+right)/2;

        TreeNode* node = new TreeNode(vals[mid]);

        node->left=build(left,mid-1);
        node->right=build(mid+1,right);

        return node;

    }


    TreeNode* balanceBST(TreeNode* root) {
      
        inorder(root);
        int left=0;
        int right=vals.size()-1;
       return build(left,right);
        
        
    }
};