class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new LinkedList<>();
        if (nums == null || nums.length == 0) {
            return res;
        }
        Arrays.sort(nums);
        boolean[] visited = new boolean[nums.length];
        dfs(nums, visited, new LinkedList<Integer>(), res);
        return res;
    }
    private void dfs(int[] nums, boolean[] visited, List<Integer> curr, List<List<Integer>> res) {
        if (curr.size() == nums.length) {
            res.add(new LinkedList<Integer>(curr));
            return;
        }
        for (int i = 0; i < nums.length; i ++) {
            if (visited[i] == true) {
                continue;
            }
            if (i == 0 || nums[i] != nums[i - 1] || (nums[i] == nums[i - 1] && visited[i - 1] == true)) {
                visited[i] = true;
                curr.add(nums[i]);
                dfs(nums, visited, curr, res);
                curr.remove(curr.size() - 1);
                visited[i] = false;
            }
        }
    }
}
