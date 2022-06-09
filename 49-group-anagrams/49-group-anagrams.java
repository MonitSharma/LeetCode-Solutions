class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> result = new ArrayList<List<String>>();
        
        Map<String, List<String>> groups = new HashMap<String, List<String>>();
        for (int i = 0; i < strs.length; i++){
            String str = strs[i];
            String key = buildAnagramsKey(str);
            
            if (!groups.containsKey(key)){
                groups.put(key, new ArrayList<String>());
            }
            groups.get(key).add(str);
        }
        
        for (Map.Entry<String, List<String>> pair : groups.entrySet()){
            result.add(pair.getValue());
        }
        
        return result;
    }
    
    public String buildAnagramsKey(String str){
        int[] map = new int[26];
        
        for (Character c : str.toCharArray()){
            map[c - 'a'] += 1;
        }
        StringBuilder build = new StringBuilder();
        for (int i = 0; i < 26; i++){
            build.append(map[i]);
            build.append((char) (i + 'a'));
        }
        return build.toString();
    }
}