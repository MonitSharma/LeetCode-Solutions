class Solution {
    public boolean checkPossibility(int[] N) {
        for (int i = 1, err = 0; i < N.length; i++)
            if (N[i] < N[i-1])
                if (err++ > 0 || (i > 1 && i < N.length - 1 && N[i-2] > N[i] && N[i+1] < N[i-1]))
                    return false;
        return true;
    }
}