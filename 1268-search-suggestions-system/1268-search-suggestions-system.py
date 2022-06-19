class Solution:
    def suggestedProducts(self, P: List[str], S: str) -> List[List[str]]:
        P.sort()
        ans, left, right = [], 0, len(P) - 1
        for i in range(len(S)):
            c, res = S[i], []
            while left <= right and (len(P[left]) == i or P[left][i] < c): left += 1
            while left <= right and (len(P[right]) == i or P[right][i] > c): right -= 1
            for j in range(3):
                if left + j > right: break
                else: res.append(P[left+j])
            ans.append(res)
        return ans