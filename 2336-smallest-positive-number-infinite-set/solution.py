class SmallestInfiniteSet:

    def __init__(self):
        self.st = deque([1])
        self.set = set([1])
    def popSmallest(self) -> int:
        m = self.st.pop()
        self.set.remove(m)
        if not self.st:
            self.st.append(m+1)
            self.set.add(m+1)
        return m

    def addBack(self, num: int) -> None:
        if num < self.st[-1]:
            self.st.append(num)
            self.set.add(num)
            return
        
        
        # TODO: use bin search
        if num in self.set or num > self.st[0]:
            return
        
        for i,x in enumerate(self.st):
            if x < num:
                break
        self.st.insert(i, num)
        self.set.add(num)