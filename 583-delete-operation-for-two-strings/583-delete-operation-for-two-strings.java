class Solution {
    public int minDistance(String W1, String W2) {
        int m = W1.length(), n = W2.length();
        if (m < n) {
            String tempStr = W1;
            W1 = W2;
            W2 = tempStr;
            int tempInt = n;
            n = m;
            m = tempInt;
        }
        char[] WA1 = W1.toCharArray(), WA2 = W2.toCharArray();
        int[] dpLast = new int[n+1], dpCurr = new int[n+1];
        for (char c1 : WA1) {
            for (int j = 0; j < n; j++) 
                dpCurr[j+1] = c1 == WA2[j]
                    ? dpLast[j] + 1
                    : Math.max(dpCurr[j], dpLast[j+1]);
            int[] tempArr = dpLast;
            dpLast = dpCurr;
            dpCurr = tempArr;
        }
        return m + n - 2 * dpLast[n];
    }
}