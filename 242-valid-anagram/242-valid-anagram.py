class Solution:
    def isAnagram(self, S: str, T: str) -> bool:
        SMap = {c: S.count(c) for c in set(S)}
        TMap = {c: T.count(c) for c in set(T)}
        return SMap == TMap