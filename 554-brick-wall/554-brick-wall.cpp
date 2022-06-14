class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> freq;
        int best = 0;
        for (int i = 0; i < wall.size(); i++) {
            int rowSum = wall[i][0];
            for (int j = 1; j < wall[i].size(); j++) {
                freq[rowSum]++;
                best = max(best, freq[rowSum]);
                rowSum += wall[i][j];
            };
        };
        return wall.size() - best;
    };
};