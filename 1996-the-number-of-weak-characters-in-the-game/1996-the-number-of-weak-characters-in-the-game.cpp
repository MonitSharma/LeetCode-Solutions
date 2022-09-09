class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(begin(properties), end(properties),
             [](const auto& a, const auto& b) {
                 return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
             });
        int result = 0, max_d = 0;
        for (int i = size(properties) - 1; i >= 0; --i) {
            if (properties[i][1] < max_d) {
                ++result;
            }
            max_d = max(max_d, properties[i][1]);
        }
        return result;
    }
};
