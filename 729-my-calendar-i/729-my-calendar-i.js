class MyCalendar {
    constructor() {
        this.calendar = {start: -1, end: -1, next: {start: Infinity, end: Infinity}}
    }
    book = function(start, end) {
        let curr = this.calendar, last = curr
        while (start >= curr.end)
            last = curr, curr = curr.next
        if (curr.start < end)
            return false
        last.next = {start: start, end: end, next: curr}
        return true
    };
}