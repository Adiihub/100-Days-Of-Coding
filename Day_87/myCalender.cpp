class MyCalendar {
private:
    vector<pair<int, int>> bookings;

public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        // Check for overlaps with existing bookings
        for (const auto& booking : bookings) {
            int booked_start = booking.first;
            int booked_end = booking.second;

            // Check if the current booking overlaps with the new one
            if (start < booked_end && end > booked_start) {
                return false; // Overlap found, booking is not possible
            }
        }
        
        // No overlap, so add the new booking
        bookings.push_back({start, end});
        return true; // Booking successful
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
