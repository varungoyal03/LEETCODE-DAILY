

class Solution {
    int cameras = 0;

public:
    int minCameraCover(TreeNode* root) {
        // If the root itself returns 0 (UNCOVERED), it has no parent to save it.
        // We must place a camera on the root.
        if (dfs(root) == 0) {
            cameras++;
        }
        return cameras;
    }

private:
    // Returns:
    // 0: UNCOVERED (Needs a camera from parent)
    // 1: HAS_CAMERA (Providing cover to parent)
    // 2: COVERED (Safe, but not providing cover to parent)
    int dfs(TreeNode* node) {
        // Base case: Null nodes don't need covering. We pretend they are already covered.
        if (node == NULL) {
            return 2; 
        }
        
        // Post-order: Get states of children first
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        // RULE 1: If any child is uncovered, I MUST install a camera here.
        if (left == 0 || right == 0) {
            cameras++;
            return 1; // Tell my parent I have a camera
        }
        
        // RULE 2: If any child has a camera, I am safely covered by it.
        if (left == 1 || right == 1) {
            return 2; // Tell my parent I am covered
        }
        
        // RULE 3: Both children are covered, but nobody is covering me.
        return 0; // Tell my parent I am uncovered and need help
    }
};