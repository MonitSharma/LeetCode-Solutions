class Solution {
    Set<String> set = new HashSet();
    String beginWord, endWord;
    Map<String, Integer> dist = new HashMap();
    List<List<String>> res;
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        this.beginWord = beginWord;
        this.endWord = endWord;
        this.res = new ArrayList();
        for (String word : wordList) {
            set.add(word);
        }
        short_path();
        if (dist.get(endWord) == null) return res;
        List<String> path = new ArrayList();
        path.add(endWord);
        dfs(endWord, path);
        return res;
    }
    
    private void short_path() {
        Queue<String> q = new LinkedList();
        q.offer(beginWord);
        dist.put(beginWord, 0);
        while(q.size() > 0) {
            String cur = q.poll();
            if (cur.equals(endWord) ) break;
            char[] charCur = cur.toCharArray();
            for (int i = 0; i < cur.length(); i++) {
                char c = charCur[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    charCur[i] = j;
                    String s = new String(charCur);
                    if (set.contains(s) && dist.get(s) == null) {
                        dist.put(s, dist.get(cur) + 1);
                        q.offer(s);
                    }
                    
                }
                charCur[i] = c;
            }
        }
    }
    
    private void dfs(String word, List<String> path) {
        if (word.equals(beginWord)) {
            List list = new ArrayList(path);
            Collections.reverse(list);
            res.add(list);
            return;
        }
        char[] charCur = word.toCharArray();
        for (int i = 0; i < word.length(); i++) {
            char c = charCur[i];
            for (char j = 'a'; j <= 'z'; j++) {
                charCur[i] = j;
                String s = new String(charCur);
                if (dist.get(s) != null && dist.get(s) + 1 == dist.get(word)) {
                    path.add(s);
                    dfs(s, path);
                    path.remove(path.size() - 1);
                }
                    
            }
            charCur[i] = c;
        }
    }
}
