class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int maxBombs = 0;
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (pow(bombs[i][2], 2) >= pow(bombs[i][0] - bombs[j][0], 2) + pow(bombs[i][1] - bombs[j][1], 2)) {
                    graph[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            unordered_set<int> visited;
            visited.insert(i);
            dfs(i, visited, graph);
            maxBombs = max(maxBombs, static_cast<int>(visited.size()));
        }

        return maxBombs;
    }

private:
    void dfs(int node, unordered_set<int>& visited, unordered_map<int, vector<int>>& graph) {
        vector<int>& neighbors = graph[node];
        for (int child : neighbors) {
            if (visited.find(child) == visited.end()) {
                visited.insert(child);
                dfs(child, visited, graph);
            }
        }
    }
};