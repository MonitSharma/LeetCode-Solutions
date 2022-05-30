class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        par.resize(edges.size()+1);
        for (int i = 0; i < par.size(); i++)
            par[i] = i;
        for (auto& e : edges)
            if (find(e[0]) == find(e[1])) return e;
            else uniun(e[0],e[1]);
        return edges[0];
    }
private:
    vector<int> par;
    int find(int x) {
        if (x != par[x]) par[x] = find(par[x]);
        return par[x];
    }
    void uniun(int x, int y) {
        par[find(y)] = find(x);
    }
};
