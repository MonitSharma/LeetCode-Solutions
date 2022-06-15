class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        W = [set() for _ in range(17)]
        for word in words:
            W[len(word)].add(word)
        dp, best = defaultdict(lambda:1), 1
        for i in range(16,0,-1):
            if len(W[i-1]) == 0: continue
            for word in W[i]:
                wVal = dp[word]
                for j in range(len(word)):
                    pred = word[0:j] + word[j+1:]
                    if pred in W[i-1] and wVal >= (dp.get(pred) or 1):
                        dp[pred] = wVal + 1
                        best = max(best, wVal + 1)
        return best