class Solution {
    public int numberOfSteps (int num) {
        int ans = 0;
        for (; num > 0; ans++)
            if (num % 2 == 1) num--;
            else num /= 2;
        return ans;
    }
}
