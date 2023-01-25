class Solution(object):
    def closestMeetingNode(self, edges, node1, node2):
        n = len(edges)
        
        def getDist(start, n):
            queue = [start]
            d = [float('inf') for i in range(n)]
            d[start] = 0
            while queue:
                node = queue.pop(0)
                x = edges[node]
                if x == -1:
                    continue
                if (d[node]+1 < d[x]):
                    d[x] = d[node]+1
                    queue.append(x)
            return d
        
        d1 = getDist(node1, n)
        d2 = getDist(node2, n)
        ans = -1
        index = -1
        for i in range(n):
            if d1[i] == float('inf') or d2[i] == float('inf'):
                continue
            dist = max(d1[i], d2[i])
            if ans == -1 or dist < ans:
                ans = dist
                index = i
        return index