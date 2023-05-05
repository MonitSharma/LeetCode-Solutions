class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int max_vowels = 0, curr_vowels = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i >= k && vowels.count(s[i - k])) {
                curr_vowels--;
            }
            if (vowels.count(s[i])) {
                curr_vowels++;
            }
            max_vowels = max(max_vowels, curr_vowels);
        }
        return max_vowels;
    }
};