class Solution:
    def isPalindrome(self, x: int) -> bool:
        # declare a temporary int and then reverse it 
        # by taking mod 10
        temp = x
        # decalre the reverse int as zero first
        reverse = 0
        # check whether the number is legitimate
        while x > 0:
            # take the mod 10 , store the remainder at the reverse
            reverse *= 10
            reverse += x % 10
            x //= 10
            # check whether both match
        return temp == reverse