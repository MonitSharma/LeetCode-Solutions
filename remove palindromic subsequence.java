class Solution {
    public int removePalindromeSub(String s) {
        // string empty
        if (s.length() == 0)
            return 0;
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            // palindrome condition
            if (s.charAt(left) == s.charAt(right)) {
                left += 1;
                right -= 1;
            }
            else 
                return 2;
        }
        return 1;
    }
}
