/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* curr, TreeNode* p,
           map<TreeNode*, TreeNode*>& parentMap) {
        if (!curr)
            return;
        parentMap[curr] = p;
        dfs(curr->left, curr, parentMap);
        dfs(curr->right, curr, parentMap);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Edge Case: Distance 0 is the target itself
        if (k == 0) return {target->val};

        
        map<TreeNode*, TreeNode*> parentMap;
        dfs(root, nullptr, parentMap);

        queue<TreeNode*> q;
        set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);
        int distance = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto top = q.front();//use auto
                q.pop();

                vector<TreeNode*> neighbors = {top->left, top->right,
                                               parentMap[top]};

                for (auto nei : neighbors) {
                    if (nei && !visited.count(nei)) {

                        q.push(nei);
                        visited.insert(nei);
                    }
                }
            }

            distance++;
            if (distance == k)
                break;
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};