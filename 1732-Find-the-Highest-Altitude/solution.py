class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        curr=0
        highest=0
        for x in gain:
            curr+=x
            highest=max(curr,highest)

        return highest 