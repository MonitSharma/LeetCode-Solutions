class Solution {
public:
    int maxScore(string s) {
        int left_zeros = 0, right_ones = count(s.begin(), s.end(), '1');
    int max_score = 0;


    // Traverse the entire string
    for (int i = 0; i < s.size()-1; ++i) {
        if (s[i] == '0') {
            left_zeros++;
        
        } else {
            right_ones--;
        }

        // calculate the score
        max_score = max(max_score, left_zeros+right_ones);
    }

    return max_score;
    }
};
