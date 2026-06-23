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
    
vector<unsigned long long> first_indices;
    unsigned long long max_width = 0;

    void dfs(TreeNode* root, int depth, unsigned long long index) {
        if (root == nullptr) return;

        // THE LEFTMOST LOCKOUT TRICK:
        // Is this the absolute first time we have ever stepped foot on this depth?
        if (depth == first_indices.size()) {
            // Yes! Record this index. It is guaranteed to be the far-left boundary.
            first_indices.push_back(index);
        }

        // Calculate the width from the far-left boundary to our current position
        unsigned long long current_width = index - first_indices[depth] + 1;
        
        // Update the global maximum width
        max_width = max(max_width, current_width);

        // Dive Left (Index * 2 + 1)
        dfs(root->left, depth + 1, index * 2 + 1);
        
        // Dive Right (Index * 2 + 2)
        dfs(root->right, depth + 1, index * 2 + 2);
    }


public:
    int widthOfBinaryTree(TreeNode* root) {
             dfs(root, 0, 0);
        return max_width;
    }
};


