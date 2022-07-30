class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        Bfreq, ans, cmax = {}, [], 0
        for word in B:
            for char in word:
                count = word.count(char)
                if char in Bfreq:
                    diff = count - Bfreq[char]
                    if diff > 0: 
                        Bfreq[char] = count
                        cmax += diff
                else: 
                    Bfreq[char] = count
                    cmax += count
            if cmax > 10: return ans
        print(Bfreq)
        for word in A:
            if len(word) < cmax: continue
            for char in Bfreq:
                if word.count(char) < Bfreq[char]: break
            else: ans.append(word)
        return ans