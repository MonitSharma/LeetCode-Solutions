class Solution {
    public boolean isAnagram(String S, String T) {
        int len = S.length();
        int[] fMap = new int[123];
        if (T.length() != len) return false;
        for (int i = 0; i < len; i++)
            fMap[S.codePointAt(i)]++;
        for (int i = 0; i < len; i++)
            if (--fMap[T.codePointAt(i)] < 0) return false;
        return true;
    }
}