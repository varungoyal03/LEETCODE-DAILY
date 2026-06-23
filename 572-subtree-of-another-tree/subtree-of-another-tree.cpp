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
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "#,"; // Mark the empty space and add a comma
        }
        
        // Root -> Left -> Right
        return to_string(root->val) + "," 
               + serialize(root->left) 
               + serialize(root->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
          string mainStr = serialize(root);
        string subStr = serialize(subRoot);

        // Step 2: The Safeguard 
        // Prepend a comma to both strings to prevent the "12 vs 2" bleeding bug
        mainStr = "," + mainStr;
        subStr = "," + subStr;

        // Step 3: The Search
        // Does the subStr exist anywhere inside the mainStr?
        // string::npos is C++ for "no position found"
        return mainStr.find(subStr) != string::npos;
    }
};
