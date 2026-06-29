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
TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
void inorder(TreeNode* root) {
        if (!root) return;

        // 1. Go Left
        inorder(root->left);

        // 2. Process Current Node: Look for the Glitch!
        if (prev != NULL && root->val < prev->val) {
            
            // If this is the FIRST violation we've seen:
            if (first == NULL) {
                first = prev;
                middle = root;
            } 
            // If this is the SECOND violation we've seen:
            else {
                last = root;
            }
        }
        
        // Update prev to the current node before we move on
        prev = root;

        // 3. Go Right
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        // Reset pointers for multiple test cases
        first = middle = last = prev = NULL;

        // Traverse the tree to find the culprits
        inorder(root);

        // Scenario 2: Distant nodes were swapped
        if (first != NULL && last != NULL) {
            swap(first->val, last->val);
        } 
        // Scenario 1: Adjacent nodes were swapped
        else if (first != NULL && middle != NULL) {
            swap(first->val, middle->val);
        }
    }
    
};