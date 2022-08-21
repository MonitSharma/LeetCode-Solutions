class Solution {
    public int[] movesToStamp(String S, String T) {
        if (S == T) return new int[]{0};
        char[] SC = S.toCharArray(), TC = T.toCharArray();
        int slen = SC.length, tlen = TC.length - slen + 1, i, j;
        List<Integer> lans = new ArrayList<>();
        Boolean tdiff = true, sdiff;
        while (tdiff)
            for (i = 0, tdiff = false; i < tlen; i++) {
                for (j = 0, sdiff = false; j < slen; j++)
                    if (TC[i+j] == '*') continue;
                    else if (TC[i+j] != SC[j]) break;
                    else sdiff = true;
                if (j == slen && sdiff) {
                    for (j = i, tdiff = true; j < slen + i; j++)
                        TC[j] = '*';
                    lans.add(0, i);
                }
            }
        for (i = 0; i < TC.length; i++) if (TC[i] != '*') return new int[]{};
        int[] ans = new int[lans.size()];
        for (i = 0; i < lans.size(); i++) ans[i] = lans.get(i);
        return ans;
    }
}