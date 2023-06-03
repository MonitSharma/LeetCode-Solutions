class Solution:
    def dfs(self, manager, informTime, adjList):
        maxTime = 0
        for subordinate in adjList[manager]:
            maxTime = max(maxTime, self.dfs(subordinate, informTime, adjList))
        return maxTime + informTime[manager]

    def numOfMinutes(self, n, headID, manager, informTime):
        adjList = defaultdict(list)
        for i in range(n):
            if manager[i] != -1:
                adjList[manager[i]].append(i)
        
        return self.dfs(headID, informTime, adjList)