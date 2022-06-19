class Solution {
    public List<List<String>> suggestedProducts(String[] P, String S) {
        Arrays.sort(P);
        List<List<String>> ans = new ArrayList<>();
        int left = 0, right = P.length - 1;
        for (int i = 0; i < S.length(); i++) {
            List<String> res = new ArrayList<>();
            char c = S.charAt(i);
            while (left <= right && (P[left].length() == i || P[left].charAt(i) < c)) left++;
            while (left <= right && (P[right].length() == i || P[right].charAt(i) > c)) right--;
            for (int j = 0; j < 3 && left + j <= right; j++)
                res.add(P[left+j]);
            ans.add(res);
        }
        return ans;
    }
}