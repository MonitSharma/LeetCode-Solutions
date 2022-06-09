class Solution:
    def searchRange(self, N: List[int], T: int) -> List[int]:
        Tleft = bisect_left(N, T)
        if Tleft == len(N) or N[Tleft] != T: return [-1, -1]
        return [Tleft, bisect_right(N, T) - 1]