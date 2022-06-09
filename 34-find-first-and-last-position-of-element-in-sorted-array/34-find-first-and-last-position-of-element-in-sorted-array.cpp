class Solution {
public:
    vector<int> searchRange(vector<int>& N, int T) {
        pair<vector<int>::iterator,vector<int>::iterator> range;
        range = equal_range(N.begin(), N.end(), T);
        int Tleft = distance(N.begin(), range.first);
        if (Tleft == N.size() || N[Tleft] != T) return {-1, -1};
        return {Tleft, (int)distance(N.begin(), range.second) - 1};
    }
};