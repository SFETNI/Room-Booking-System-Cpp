#ifndef ROOM_BOOKING_SYSTEM_H
#define ROOM_BOOKING_SYSTEM_H

#include <map>

template<typename Time, typename Status>
class RoomBookingSystem {
    Status m_defaultStatus; 
    std::map<Time, Status> m_bookings; 

public:

    RoomBookingSystem(Status const& defaultStatus);


    template<typename Status_>
    void assignBooking(Time const& startTime, Time const& endTime, Status_&& newStatus);

    Status const& getStatusAt(Time const& time) const;
};


template<typename Time, typename Status>
RoomBookingSystem<Time, Status>::RoomBookingSystem(Status const& defaultStatus)
    : m_defaultStatus(defaultStatus)
{}

template<typename Time, typename Status>
template<typename Status_>
void RoomBookingSystem<Time, Status>::assignBooking(Time const& startTime, Time const& endTime, Status_&& newStatus) {
    if (!(startTime < endTime)) return; // Invalid interval

    if (m_bookings.empty()) {
        if (newStatus == m_defaultStatus) return; 
        m_bookings.emplace(startTime, newStatus);  
        m_bookings.emplace(endTime, m_defaultStatus);  
        return; 
    }


    auto itLow = m_bookings.lower_bound(startTime); 
    if (itLow != m_bookings.begin()) {   
        auto itPrev = std::prev(itLow);
        if (itPrev->first >= startTime) { 
            itLow = itPrev;
        }
    } 

    auto itHigh = m_bookings.lower_bound(endTime);  
    if (itLow == m_bookings.end() || itHigh == m_bookings.begin()) {
        if (newStatus == m_defaultStatus) return; 
        m_bookings.emplace(startTime, newStatus); 
        m_bookings.emplace(endTime, m_defaultStatus);   
        return;
    }

    Status statusBeforeLow = m_defaultStatus; 
    if (itLow != m_bookings.begin()) {
        statusBeforeLow = std::prev(itLow)->second;
    }

    Status statusAfterHigh = m_defaultStatus;  
    if (itHigh != m_bookings.end()) {
        statusAfterHigh = std::prev(itHigh)->second;
    }


    m_bookings.erase(itLow, itHigh); 


    if (statusBeforeLow != newStatus) {
        m_bookings.emplace(startTime, newStatus);
    }


    if (statusAfterHigh != newStatus) {
        m_bookings.emplace(endTime, statusAfterHigh);
    }
}

template<typename Time, typename Status>
Status const& RoomBookingSystem<Time, Status>::getStatusAt(Time const& time) const {
    auto it = m_bookings.upper_bound(time);
    if (it == m_bookings.begin()) {
        return m_defaultStatus;
    } else {
        return (--it)->second;
    }
}

#endif 
