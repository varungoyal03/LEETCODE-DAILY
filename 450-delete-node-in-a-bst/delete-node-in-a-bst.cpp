/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        // 1. Search for the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        // 2. We found the node to delete!
        else {
            // --- HANDLE 0 OR 1 CHILD CASES SEPARATELY ---

            // If there is no left child (covers 0 children and 1 right child)

            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // If there is no right child (covers 1 left child)
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // --- HANDLE 2 CHILDREN CASE ---

            // We only reach this point if BOTH left and right children exist.
            TreeNode* temp = root->right;

            // Go to the absolute leftmost node of the right subtree
            while (temp->left)
                temp = temp->left;

            // Attach the original node's left subtree here
            temp->left = root->left;

            // Store the new top of this subtree, delete the old node, and
            // return
            TreeNode* newRoot = root->right;
            delete root;
            return newRoot;
        }

        return root;
    }
};