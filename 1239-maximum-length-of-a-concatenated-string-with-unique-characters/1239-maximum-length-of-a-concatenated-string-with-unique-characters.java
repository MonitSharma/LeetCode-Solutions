class Solution {
  public int maxLength(List<String> arr) {
        List<Integer> dp = new ArrayList<>();
    dp.add(0);
    int res = 0;
    for (String s : arr) {
      int a = 0, dup = 0;
      for (char c : s.toCharArray()) {
        dup |= a & (1 << (c - 'a'));
        a |= 1 << (c - 'a');
      }
      if (dup > 0)    continue;
      for (int i = dp.size() - 1; i >= 0; i--) {
        if ((dp.get(i) & a) > 0) continue;
        dp.add(dp.get(i) | a);
        res = Math.max(res, Integer.bitCount(dp.get(i) | a));
      }
    }
    return res;
  }
}