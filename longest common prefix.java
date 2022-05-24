class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0){
            return "";
        }
        String pref = strs[0];
        for(String s : strs){
            int len = Math.min(pref.length(), s.length());
            for(int i = len; i >= 0; i--){
                if(pref.indexOf(s.substring(0, i)) == 0){
                    pref = s.substring(0, i);
                    break;
                }
            }
        }
        return pref;
    }
}