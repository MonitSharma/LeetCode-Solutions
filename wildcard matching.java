class Solution {
    public boolean isMatch(String s, String p) {
       Boolean[][] dp = new Boolean[s.length()][p.length()];
       return match(s, p, 0, 0, dp); 
    }
    
    public boolean match(String s, String p, int i, int j, Boolean[][] dp) {
        if(i >= s.length() && j >= p.length()) {
            return true;
        }
        if(i >= s.length() && p.charAt(j) == '*') {
            return match(s, p, i, j+1, dp);
        }
        if(i >= s.length()) {
            return false;
        }
        if(j >= p.length()) {
            return false;
        }
        if(dp[i][j] != null) return dp[i][j];
        if(p.charAt(j) == '*') {
            dp[i][j] = match(s, p, i+1, j+1, dp) || match(s, p, i+1, j, dp) || match(s, p, i, j+1, dp);
        } else if(p.charAt(j) == s.charAt(i)) {
            dp[i][j] = match(s, p, i+1, j+1, dp);
        } else if(p.charAt(j) == '?'){
            dp[i][j] = match(s, p, i+1, j+1, dp);
        }else{ 
            dp[i][j] = false;
        }
        return dp[i][j];
    }
}
