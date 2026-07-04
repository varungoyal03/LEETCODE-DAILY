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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        
        // 1. Find the height of the extreme left and right paths
        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);
        
        // 2. If they are equal, it's a Perfect Binary Tree! Calculate instantly.
        if (leftHeight == rightHeight) {
            // (1 << leftHeight) is a bitwise shift equivalent to 2^leftHeight
            return (1 << leftHeight) - 1; 
        }
        
        // 3. If not perfect, split the tree and recurse
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    // Helper to calculate the extreme left height
    int getLeftHeight(TreeNode* node) {
        int height = 0;
        while (node != NULL) {
            height++;
            node = node->left;
        }
        return height;
    }
    
    // Helper to calculate the extreme right height
    int getRightHeight(TreeNode* node) {
        int height = 0;
        while (node != NULL) {
            height++;
            node = node->right;
        }
        return height;
    }
};