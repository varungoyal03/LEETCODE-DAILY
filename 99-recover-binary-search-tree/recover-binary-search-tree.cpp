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
public:TreeNode* first;
    TreeNode* second;
    TreeNode* prev;

    void inorder(TreeNode* root) {
        if (!root) return;

        // 1. Go Left
        inorder(root->left);

        // 2. Process Current Node: Look for the Glitch!
        // (A glitch is when the previous number is strictly greater than the current number)
        if (prev != NULL && prev->val > root->val) {
            
            // If this is the VERY FIRST violation:
            if (first == NULL) {
                first = prev;
                second = root; // Tentatively assume they are adjacent
            } 
            // If this is the SECOND violation:
            else {
                second = root; // Overwrite our assumption with the distant node
            }
        }
        
        // Update prev to the current node before we move on
        prev = root;

        // 3. Go Right
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        // Reset pointers for multiple test cases
        first = second = prev = NULL;

        // Traverse the tree to find the culprits
        inorder(root);

        // Swap the values to restore the BST
        if (first != NULL && second != NULL) {
            swap(first->val, second->val);
        }
    }
    
};