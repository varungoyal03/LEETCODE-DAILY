

class Solution {
private:
    // FUNCTION 2: The Recursive Engine
    // Notice the '&' next to prev. This is the shared tracker!
    void flattenHelper(TreeNode* current, TreeNode*& prev) {
        // Base case: Hit a dead end
        if (current == nullptr) return;

        // 1. Dive completely to the Right
        flattenHelper(current->right, prev);

        // 2. Dive completely to the Left
        flattenHelper(current->left, prev);

        // 3. Process the Current Node
        // Connect the current node to the last node we processed
        current->right = prev;
        
        // Erase the left branch to ensure it is a straight line
        current->left = nullptr;

        // 4. Update the shared tracker for the next node up the chain
        prev = current;
    }

public:
    // FUNCTION 1: The Main Wrapper
    void flatten(TreeNode* root) {
        // Create a clean tracker strictly for this specific function call
        TreeNode* prev = nullptr;
        
        // Start the engine and pass the tracker in!
        flattenHelper(root, prev);
    }
};