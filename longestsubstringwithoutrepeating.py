class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        rep_set = set()
        l = 0
        
        result = 0
        
        for r in range(len(s)):
            
            while s[r] in rep_set:
                rep_set.remove(s[l])
                l +=1 
            rep_set.add(s[r])
            result = max(result, r - l + 1)
        return result