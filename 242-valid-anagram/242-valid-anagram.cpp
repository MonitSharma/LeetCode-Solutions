class Solution {
public:
    bool isAnagram(string S, string T) {
        int len = S.length();
        int fMap [123] = {0};
        if (T.length() != len) return false;
        for (int i = 0; i < len; i++)
            fMap[int(S[i])]++;
        for (int i = 0; i < len; i++)
            if (fMap[int(T[i])]-- == 0) return false;
        return true;
    }
};