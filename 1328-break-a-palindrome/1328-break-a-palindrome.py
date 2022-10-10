class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        n = len(palindrome)
        for i in range(n//2):
            if palindrome[i] != 'a':
                return palindrome.replace(palindrome[i], 'a', 1)
        return palindrome[:-1] + 'b' if n > 1 else ""