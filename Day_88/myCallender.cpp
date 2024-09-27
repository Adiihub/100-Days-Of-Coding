class MyCalendarTwo {
public:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlaps;
    
    MyCalendarTwo() { }
    
    bool book(int start, int end) {
        for (auto& [s, e] : overlaps) {
            if (max(s, start) < min(e, end)) {
                return false;
            }
        }
        
        for (auto& [s, e] : bookings) {
            int overlapStart = max(s, start);
            int overlapEnd = min(e, end);
            if (overlapStart < overlapEnd) {
                overlaps.push_back({overlapStart, overlapEnd});
            }
        }
        
        // Add the new booking to the bookings list
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
