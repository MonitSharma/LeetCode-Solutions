class Solution {
    final char[][] L = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},
    {'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

    public List<String> letterCombinations(String D) {
        int len = D.length();
        List<String> ans = new ArrayList<>();
        if (len == 0) return ans;
        bfs(0, len, new StringBuilder(), ans, D);
        return ans;
    }

    public void bfs(int pos, int len, StringBuilder sb, List<String> ans, String D) {
        if (pos == len) ans.add(sb.toString());
        else {
            char[] letters = L[Character.getNumericValue(D.charAt(pos))];
            for (int i = 0; i < letters.length; i++)
                bfs(pos+1, len, new StringBuilder(sb).append(letters[i]), ans, D);
        }
    }
}
