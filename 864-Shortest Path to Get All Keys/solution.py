class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        m=len(grid)
        n=len(grid[0])
        arr=deque([])
        numOfKeys=0
        keys={'a':0,'b':1,'c':2,'d':3,'e':4,'f':5}
        locks={'A':0,'B':1,'C':2,'D':3,'E':4,'F':5}
        for i in range(m):
            for j in range(n):
                if grid[i][j]=='@':
                    arr.append((i,j,0,0))
                elif grid[i][j] in keys:
                    numOfKeys+=1

        visited=set()
        while arr:
            size=len(arr)
            for _ in range(size):
                i,j,found,steps=arr.popleft()
                curr=grid[i][j]
                if curr in locks and not (found>>locks[curr]) & 1 or curr=='#':
                    continue

                if curr in keys:
                    found |=1<<keys[curr]
                    if found==(1<<numOfKeys)-1:
                        return steps

                for x,y in [(i+1,j),(i,j+1),(i-1,j),(i,j-1)]:
                    if 0<=x<m and 0<=y<n and (x,y,found) not in visited:
                        visited.add((x,y,found))
                        arr.append((x,y,found,steps+1))

        return -1   