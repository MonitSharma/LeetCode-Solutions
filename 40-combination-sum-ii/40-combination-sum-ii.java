public class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if(candidates == null || candidates.length == 0) return result;
        ArrayList<Integer> current = new ArrayList<Integer>();
        Arrays.sort(candidates);
        combinationSum(candidates, target, 0, current, result);
        return result;
    }
    public void combinationSum(int[] candidates, int target, int j, ArrayList<Integer> curr, List<List<Integer>> result){
        if(target == 0){
            ArrayList<Integer> temp = new ArrayList<Integer>(curr);
            result.add(temp);
            return;
        }
        for(int i=j; i<candidates.length; i++){
            if (target < candidates[i]){
                return;
            }
            if (i == j || candidates[i] != candidates[i-1]){
                curr.add(candidates[i]);
                combinationSum(candidates, target - candidates[i], i + 1, curr, result);
                curr.remove(curr.size()-1);
            }
        }//for i
    }//combinationSum
}//Solution
