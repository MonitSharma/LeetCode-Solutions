class Solution {
public:
    int minRefuelStops(int T, int F, vector<vector<int>>& S) {
        int n = S.size(), ans = 0;
        priority_queue<int> pq;
        for (int i = 0; i <= n; i++) {
            int dist = i == n ? T : S[i][0];
            while (F < dist) {
                if (!pq.size()) return -1;
                F += pq.top(), ans++;
                pq.pop();
            }
            if (i < n) pq.push(S[i][1]);
        }
        return ans;
    }
};