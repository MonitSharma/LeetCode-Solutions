class Solution {
    public double average(int[] salary) {
        final int N = salary.length;
        int min=salary[0],max=salary[0];
        double sum = salary[0];
        for (int i = 1; i < N; i++) {
            if (salary[i]<min) min=salary[i];
            if (salary[i]>max) max=salary[i];
            sum += salary[i];
        }
        sum = sum - max - min;
        return sum / (N - 2);
    }
}