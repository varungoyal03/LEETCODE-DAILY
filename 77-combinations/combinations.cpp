class Solution {
public:
void dfs(int index, int n, int k, vector<int>& currentComb, vector<vector<int>>& result) {
        // BASE CASE 1: Success! We filled our team of size 'k'
        if (currentComb.size() == k) {
            result.push_back(currentComb);
            return;
        }
        
    // ==========================================
// BASE CASE 2: The "Mathematical Impossibility" Prune
// ==========================================
int elementsNeeded = k - currentComb.size();
int elementsAvailable = n - index + 1;

// If we need more numbers than the universe has left to offer, stop exploring!
if (elementsNeeded > elementsAvailable) {
    return;
}

        // ==========================================
        // BRANCH 1: PICK THE CURRENT NUMBER
        // ==========================================
        currentComb.push_back(index);
        
        // Move to the next number
        dfs(index + 1, n, k, currentComb, result);
        
        // Backtrack: Remove the number so the next branch can try without it
        currentComb.pop_back();

        // ==========================================
        // BRANCH 2: DO NOT PICK THE CURRENT NUMBER
        // ==========================================
        // We leave the array exactly as it is and just move to the next number.
        dfs(index + 1, n, k, currentComb, result);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> currentComb;
        
        // Start making choices from number 1
        dfs(1, n, k, currentComb, result);
        
        return result;
    }
};