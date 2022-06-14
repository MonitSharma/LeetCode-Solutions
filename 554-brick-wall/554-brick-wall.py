class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        freq = defaultdict(int)
        for row in wall:
            rowSum = row[0]
            for j in range(1, len(row)):
                freq[rowSum] += 1
                rowSum += row[j]
        return len(wall) - max(freq.values() or [0])