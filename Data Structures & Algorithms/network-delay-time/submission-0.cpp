
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // STEP 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto it : times) {

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        // STEP 2: Initialize distance array
        vector<int> dist(n + 1, INT_MAX);

        // STEP 3: Create min heap
        // {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        // STEP 4: Initialize source
        dist[k] = 0;
        pq.push({0, k});

        // STEP 5: Dijkstra
        while(!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            // Ignore outdated entries
            if(d > dist[node]) {
                continue;
            }

            // STEP 6: Explore neighbors
            for(auto it : adj[node]) {

                int adjNode = it.first;
                int wt = it.second;

                // STEP 7: Relaxation
                if(d + wt < dist[adjNode]) {

                    dist[adjNode] = d + wt;

                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // STEP 8: Find maximum shortest distance
        int ans = 0;

        for(int i = 1; i <= n; i++) {

            // If any node is unreachable
            if(dist[i] == INT_MAX) {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
