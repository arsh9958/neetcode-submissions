
class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {
        if(node == NULL) return NULL;

        // Already cloned
        if(mp.count(node)) {
            return mp[node];
        }

        // Create a clone
        Node* clone = new Node(node->val);

        // Store before visiting neighbours
        mp[node] = clone;

        // Clone all neighbours
        for(auto neighbour : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbour));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        return dfs(node);
    }
};
