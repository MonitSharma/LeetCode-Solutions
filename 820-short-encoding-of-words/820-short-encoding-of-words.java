class Solution {
    public int minimumLengthEncoding(String[] W) {
        Set<String> set = new HashSet<>(Arrays.asList(W));
        for (String word : W)
            if (set.contains(word))
                for (int i = 1; i < word.length(); i++) 
                    set.remove(word.substring(i));
        int ans = set.size();
        for (String word : set) ans += word.length();
        return ans;
    }
}