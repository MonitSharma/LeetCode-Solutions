#include <string.h>


int maxScore(char* s) {
    int left_zeros = 0, right_ones = 0, max_score = 0;
    // count total number of ones
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] == '1') right_ones++;

    }
    
    // traverse the string
    for (int i = 0; s[i+1] != '\0'; i++) {
        if (s[i] == '0'){
            left_zeros++;

        } else {
            right_ones--;
        }

        // calculate the score
        int score = left_zeros + right_ones;
        if (score > max_score) max_score = score;
    }

    return max_score;
}