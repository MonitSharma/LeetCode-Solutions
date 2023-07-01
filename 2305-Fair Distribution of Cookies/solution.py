class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        def dfs(p):
            nonlocal best
            if p==len(cookies):
                best = min(best, max(split))
                return
            # give to a new kid
            if len(split)<k:
                split.append(cookies[p])
                dfs(p+1)
                split.pop()
            # give to a kid that already has cookies
            for i in range(len(split)):
                if split[i]+cookies[p] < best:
                    split[i] += cookies[p]
                    dfs(p+1)
                    split[i] -= cookies[p]

        split = []
        best = float("inf")
        dfs(0)
        return best