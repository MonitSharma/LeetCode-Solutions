class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        degree = [0] * n
        for a, b in roads:
            degree[a] += 1
            degree[b] += 1
        road_set = set(tuple(road) for road in roads)
        max_rank = 0
        for i in range(n):
            for j in range(i+1, n):
                rank = degree[i] + degree[j]
                if (i, j) in road_set or (j, i) in road_set:
                    rank -= 1
                max_rank = max(max_rank, rank)
        return max_rank