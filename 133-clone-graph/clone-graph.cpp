class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }

        // 1. Declare the unordered_map
        // Key: Pointer to Original Node -> Value: Pointer to Cloned Node
        unordered_map<Node*, Node*> visited;

        queue<Node*> q;
        q.push(node);
        
        Node* rootnew = new Node(node->val);
        
        // 2. Map the original pointer to the new cloned pointer
        visited[node] = rootnew; 

        while (!q.empty()) {
            Node* originaltemp = q.front();
            q.pop();

            // 3. Look up the cloned node using the original node's pointer
            Node* temp = visited[originaltemp];

            for(Node* nb : originaltemp->neighbors) {
                
                // 4. Check if the neighbor exists in the map
                // visited.find(nb) == visited.end() means "Not Found"
                if (visited.find(nb) == visited.end()) {
                    
                    Node* cloned = new Node(nb->val);
                    temp->neighbors.push_back(cloned);
                    
                    // Add the new clone to the map using the neighbor's pointer
                    visited[nb] = cloned; 
                    q.push(nb);

                } else {
                    // If it already exists, just link it
                    temp->neighbors.push_back(visited[nb]);
                }
            }
        }

        return rootnew;
    }
};