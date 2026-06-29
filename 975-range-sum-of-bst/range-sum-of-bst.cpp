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
      int find(TreeNode* root, int l, int h){
       
         if(!root){return 0;}
     
         if(root->val <l ){
            return find(root->right,l,h);  
         }
        if(root->val >h ){                
            return find(root->left,l,h);
         }

      
           
    
            return root->val+ find(root->left,l,h)+find(root->right,l,h);

            

         

         
      }
    int rangeSumBST(TreeNode* root, int low, int high) {

        return find(root,low,high);
    }
};