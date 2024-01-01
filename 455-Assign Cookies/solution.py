class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        
        # 1. Sort both the array g and s in ascending order
        g.sort()   # O(n log n)
        s.sort()   # O(m log m)

        # 2. Initialize the pointer j(cookies) to 0
        j = 0

        # 3. Loop through each child's greed factor in g
        for _,__ in enumerate(g):  # O(n+m)
            # 4. Move through the cookie sizes until we find some
            while j < len(s) and s[j] < __:
                j += 1
            # 5. if there are no more cookies left, return the number of children so far
            if j >= len(s):
                return _
            # 6. Move to the next cookie
            j += 1
        
        return len(g)


        
        