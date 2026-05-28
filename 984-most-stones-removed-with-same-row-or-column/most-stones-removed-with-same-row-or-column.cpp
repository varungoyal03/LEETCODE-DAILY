class Dsu {
private:
    int set_count = 0; // total number of disjoint sets
    vector<int> parent,
        size; // parent[i] = leader of set; size[i] = size of root's set

public:
    Dsu() {}
    // Constructor: initializes DSU with n elements, each in its own set
    Dsu(int n) : set_count(n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // each node is its own parent (root)
            size[i] = 1;   // each set initially has size 1
        }
    }

    // Returns current number of disjoint sets
    int count() { return set_count; }

    // Finds the root of node `id`, with path compression
    int find(int id) {
        if (id != parent[id]) {
            return parent[id] = find(parent[id]);
        } // compress path
        return id;
    }

    // Unites the sets containing `x` and `y` (by size); returns true if merged
    bool unite(int x, int y) {
        x = find(x), y = find(y); // find leaders
        if (x == y)
            return false; // already in the same set
        if (size[x] < size[y])
            swap(x, y);     // ensure x has larger size
        parent[y] = x;      // attach y to x
        size[x] += size[y]; // update size
        set_count--;        // one less component now
        return true;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int maxRow = 0;
        int maxCol = 0;
        
        // 1. Find the maximum row and column to size our DSU appropriately
        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        int n=stones.size();

        Dsu dsu(maxRow+maxCol+2);

        for (auto& stone : stones) {
            int row = stone[0];
            // Offset the column so it doesn't collide with row indices
            int col = stone[1] + maxRow + 1; 
            
            dsu.unite(row, col);
        }

        // 4. Count only the active components that actually contain stones
        unordered_set<int> activeComponents;
        for (auto& stone : stones) {
            // Inserting the root of the row will automatically deduplicate
            activeComponents.insert(dsu.find(stone[0]));
        }
        
        
   return n-activeComponents.size(); }
};