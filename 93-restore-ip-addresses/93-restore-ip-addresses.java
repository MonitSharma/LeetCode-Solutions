public class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> result = new LinkedList<String>();
        dfs(s, result, "", 0, 12, 4);
        return result;
    }
    private void dfs(String s, List<String> result, String curr, int start, int max, int min) {
        if (s.length() - start > max || s.length() - start < min) {
            return;
        }
        if (max == 0 && start == s.length()) {
            result.add(curr.substring(1));
            return;
        }
        if (s.charAt(start) == '0') {
            dfs(s, result, curr + ".0", start + 1, max - 3, min - 1);
            return;
        }
        for (int i = 0; i < 3; i ++) {
            if (start + i + 1 <= s.length()) {
                int tmp = Integer.parseInt(s.substring(start, start + i + 1));
                if (tmp >=0 && tmp <= 255) {
                    dfs(s, result, curr + "." + tmp, start + i + 1, max - 3, min - 1);
                }
            }
        }

    }
}