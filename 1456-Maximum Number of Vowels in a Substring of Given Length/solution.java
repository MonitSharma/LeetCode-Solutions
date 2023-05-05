class Solution {
    public int maxVowels(String s, int k) {
        Set<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));
        int max_vowels = 0, curr_vowels = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i >= k && vowels.contains(s.charAt(i - k))) {
                curr_vowels--;
            }
            if (vowels.contains(s.charAt(i))) {
                curr_vowels++;
            }
            max_vowels = Math.max(max_vowels, curr_vowels);
        }
        return max_vowels;
    }
}