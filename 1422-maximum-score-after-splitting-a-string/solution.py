class Solution:
    def maxScore(self, s:str) -> int:
        # initialize the counts
        left_zeros = 0
        right_ones = s.count('1') # how many ones are in the string
        max_score = 0


        # now traverse the string
        for i in range(len(s)-1): # since split point must leave a non-empty substring
            if s[i] == '0':
                left_zeros += 1
            else:
                right_ones -= 1

            # now calculate the score
            max_score = max(max_score, left_zeros + right_ones)

        return max_score
