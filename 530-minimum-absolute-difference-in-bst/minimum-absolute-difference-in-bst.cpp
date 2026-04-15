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
int ans=INT_MAX;

   void minDiff(TreeNode* root,int &prev){//LNR
     if(!root){return;}
       
     minDiff(root->left,prev);

     if(prev!=INT_MIN){
        ans=min(ans, root->val - prev);
     }  
     prev=root->val;

      minDiff(root->right,prev);
   }   
    int getMinimumDifference(TreeNode* root) {
        int prev=INT_MIN;   //start from int min since no node vale has int_min
        minDiff(root,prev);
        return ans;
    }
};