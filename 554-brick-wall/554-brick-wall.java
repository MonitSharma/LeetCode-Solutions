class Solution {
    int best = 0;
    Map<Integer, Integer> freq = new HashMap<>();
    public int leastBricks(List<List<Integer>> wall) {
        for (int i = 0; i < wall.size(); i++)
            processRow(wall.get(i));
        return wall.size() - best;
    }
    public void processRow(List<Integer> row) {
        int rowSum = row.get(0);
        for (int j = 1; j < row.size(); j++) {
            int f = freq.getOrDefault(rowSum, 0) + 1;
            freq.put(rowSum, f);
            if (f > best) best = f;
            rowSum += row.get(j);
        } 
    }
}