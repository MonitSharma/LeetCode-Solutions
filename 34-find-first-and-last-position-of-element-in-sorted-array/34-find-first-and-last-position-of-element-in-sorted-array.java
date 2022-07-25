class Solution {
    public int[] searchRange(int[] N, int T) {
        int Tleft = find(T, N, 0);
        if (Tleft == N.length || N[Tleft] != T) return new int[] {-1, -1};
        return new int[] {Tleft, find(T+1, N, Tleft) - 1};
    }
    public int find(int target, int[] arr, int left) {
        int right = arr.length - 1;
        while (left <= right) {
            int mid = left + right >> 1;
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
}