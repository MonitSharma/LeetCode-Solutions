class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        try:
            return 0 if len(needle) == 0 else haystack.index(needle, 0, len(haystack))
        except:
            return -1