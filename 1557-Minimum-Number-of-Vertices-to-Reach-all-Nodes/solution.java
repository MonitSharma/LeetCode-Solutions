class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        List<Integer> ans = new ArrayList<Integer>();
        Set<Integer> endset = new HashSet<Integer>();

        for (List<Integer> edge: edges) {
            endset.add(edge.get(1));
        }

        for (int i = 0; i < n; ++i) {
            if (!endset.contains(i)) {
                ans.add(i);
            }
        }
        return ans;
    }
}
// 