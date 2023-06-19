class Solution {
  public int largestAltitude(int[] gain) {
    int altitude = 0, max = 0;

    for (var g : gain) {
      altitude += g;
      max = Math.max(max, altitude);
    }
    return max;
  }
}