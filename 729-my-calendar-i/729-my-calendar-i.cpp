class MyCalendar {
public:
    set<pair<int, int>> calendar = {{INT_MAX, INT_MAX}};
    bool book(int start, int end) {
        auto pair = calendar.upper_bound({start, end});
        bool res = end <= pair->second;
        if (res) calendar.insert({end, start});
        return res;
    }
};