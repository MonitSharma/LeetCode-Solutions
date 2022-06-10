class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> map;

        for(int i = 0, j = 0; j < s.size(); j++){
            if(map.find(s[j]) != map.end()){
                i = max(map[s[j]], i);
            }
            ans = max(ans, j - i + 1);
            map[s[j]] = j + 1;
        }

        return ans;
    }
};