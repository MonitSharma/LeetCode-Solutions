class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        self.dic = set(words)
        return [word for word in words if self.DFS(word, {})]
    
    def DFS(self, word, memo) -> bool:
        if word in memo: return memo[word]
        
        memo[word] = False
        for i in range(1, len(word)):
            prefix = word[:i]
            suffix = word[i:]
            
            if prefix in self.dic and suffix in self.dic: 
                memo[word] = True
                break
            if prefix in self.dic and self.DFS(suffix, memo):
                memo[word] = True
                break
        return memo[word]
