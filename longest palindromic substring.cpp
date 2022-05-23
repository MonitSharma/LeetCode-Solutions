class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0, len = 0, len1 = 0, len2 = 0;
        int left = 0, right = 0;
        for(int i = 0; i<s.length(); i++)
        {
            len1 = palindrome(s, i, i);
            len2 = palindrome(s, i, i+1);
            len = max(len1, len2);
            if (len > max_len)
            {
                max_len = len;
                left = i - (len-1)/2;
                right = i + len/2;
            }
                
        }
        return s.substr(left, max_len);
    }
    
    int palindrome (string s, int left, int right)
    {
        while (left>=0 && right < s.length() && s[left] == s[right])
        {
                left--;
                right++;            
        }
        return right - left - 1;
    }
};