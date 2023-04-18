class Solution {
    public int numWays(String[] words, String target) {
        final int MODULO = 1000000007;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int targetLength = target.length();
        int wordLength = words[0].length();
        if (targetLength > wordLength)
            return 0;
        for (String word : words) {
            for (int i = 0; i < wordLength; i++) {
                int letterIndex = word.charAt(i) - 'a';
                int key = i * 26 + letterIndex;
                int count = map.getOrDefault(key, 0) + 1;
                map.put(key, count);
            }
        }
        long[][] dp = new long[targetLength][wordLength];
        int letterIndex0 = target.charAt(0) - 'a';
        int maxStart0 = wordLength - targetLength;
        for (int j = 0; j <= maxStart0; j++) {
            int key = j * 26 + letterIndex0;
            dp[0][j] = map.getOrDefault(key, 0);
            if (j > 0)
                dp[0][j] = (dp[0][j - 1] + dp[0][j]) % MODULO;
        }
        for (int i = 1; i < targetLength; i++) {
            int letterIndex = target.charAt(i) - 'a';
            int maxStart = wordLength - targetLength + i;
            for (int j = i; j <= maxStart; j++) {
                int key = j * 26 + letterIndex;
                long curCount = map.getOrDefault(key, 0);
                if (curCount > 0)
                    dp[i][j] = dp[i - 1][j - 1] * curCount % MODULO;
                if (j > i)
                    dp[i][j] = (dp[i][j - 1] + dp[i][j]) % MODULO;
            }
        }
        return (int) dp[targetLength - 1][wordLength - 1];
    }
}



