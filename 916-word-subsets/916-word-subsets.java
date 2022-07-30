class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        int[] Bfreq = new int[26], check = new int[26];
        int cmax = 0;
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < B.length; i++, Arrays.fill(check, 0)) {
            for (char c : B[i].toCharArray())
                check[c - 'a']++;
            for (int j = 0; j < 26; j++) {
                int diff = check[j] - Bfreq[j];
                if (diff > 0) {
                    cmax += diff;
                    Bfreq[j] += diff;
                }
            }
            if (cmax > 10) return ans;
        }
        for (int i = 0; i < A.length; i++, Arrays.fill(check, 0)) {
            int j;
            for (char c : A[i].toCharArray())
                check[c - 'a']++;
            for (j = 0; j < 26; j++)
                if (check[j] < Bfreq[j]) break;
            if (j == 26) ans.add(A[i]);
        }
        return ans;
    }
}