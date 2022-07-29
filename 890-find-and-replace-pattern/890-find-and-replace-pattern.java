class Solution {
    List<String> ans;
    Map<Character, Character> codex;
    char[] cipher;

    public List<String> findAndReplacePattern(String[] words, String pattern) {
        ans = new ArrayList<>();
        codex = new HashMap<>();
        cipher = pattern.toCharArray();
        for (int i = 0; i < pattern.length(); i++)
            cipher[i] = translate(cipher[i]);
        for (String word : words) compare(word);
        return ans;
    }
    private char translate(char c) {
        if (!codex.containsKey(c))
            codex.put(c, (char)(97 + codex.size()));
        return codex.get(c);
    }
    private void compare(String word) {
        codex.clear();
        for (int i = 0; i < word.length(); i++)
            if (translate(word.charAt(i)) != cipher[i]) return;
        ans.add(word);
    }
}