class Solution:
    def minimumLengthEncoding(self, W: List[str]) -> int:
        wset = set(W)
        for word in W:
            if word in wset:
                for i in range(1,len(word)):
                    wset.discard(word[i:])
        return len("#".join(list(wset))) + 1