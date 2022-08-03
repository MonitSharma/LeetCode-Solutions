from sortedcontainers import SortedDict
class MyCalendar:
    def __init__(self):
        self.calendar = SortedDict({float('inf'):float('inf')})        
    def book(self, start: int, end: int) -> bool:
        ix = self.calendar.bisect_right(start)
        k,v = self.calendar.peekitem(ix)
        res = end <= v
        if res: self.calendar[end] = start
        return res