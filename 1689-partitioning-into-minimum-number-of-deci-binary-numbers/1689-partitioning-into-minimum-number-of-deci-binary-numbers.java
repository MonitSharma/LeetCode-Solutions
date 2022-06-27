class Solution {
    public int minPartitions(String n) {
        char best = '0';
        for (char c : n.toCharArray())
            if (c > best) best = c;
        return best - '0';
    }
}