
#include "RoomBookingSystem.h"
#include <iostream>
#include <cassert>

void test_room_booking_system() {
    std::cout << "Created RoomBookingSystem with initial status 'Available'" << std::endl;
    RoomBookingSystem<int, char> roomSystem('A'); // 'A' = Available

    // Test 1: Book room [1, 3) as 'Booked'
    std::cout << "Running Test 1: Book [1, 3) as 'B'" << std::endl;
    roomSystem.assignBooking(1, 3, 'B');
    assert(roomSystem.getStatusAt(0) == 'A'); // Before the interval, room is 'Available'
    assert(roomSystem.getStatusAt(1) == 'B'); // During the interval, room is 'Booked'
    assert(roomSystem.getStatusAt(2) == 'B'); // During the interval, room is 'Booked'
    assert(roomSystem.getStatusAt(3) == 'A'); // After the interval, room is 'Available'
    std::cout << "Test 1 passed!" << std::endl;

    // Test 2: Book room [2, 5) as 'Under Maintenance'
    std::cout << "Running Test 2: Book [2, 5) as 'M'" << std::endl;
    roomSystem.assignBooking(2, 5, 'M');
    assert(roomSystem.getStatusAt(1) == 'B'); 
    assert(roomSystem.getStatusAt(2) == 'M');
    assert(roomSystem.getStatusAt(4) == 'M'); 
    assert(roomSystem.getStatusAt(5) == 'A'); 
    std::cout << "Test 2 passed!" << std::endl;

    // Test 3: Book room [0, 2) as 'Cleaning'
    std::cout << "Running Test 3: Book [0, 2) as 'C'" << std::endl;
    roomSystem.assignBooking(0, 2, 'C');
    assert(roomSystem.getStatusAt(0) == 'C'); 
    assert(roomSystem.getStatusAt(1) == 'C'); 
    assert(roomSystem.getStatusAt(2) == 'M'); 
    std::cout << "Test 3 passed!" << std::endl;

    // Test 4: Book room [4, 6) as 'Occupied'
    std::cout << "Running Test 4: Book [4, 6) as 'O'" << std::endl;
    roomSystem.assignBooking(4, 6, 'O');
    assert(roomSystem.getStatusAt(4) == 'O'); 
    assert(roomSystem.getStatusAt(5) == 'O'); 
    assert(roomSystem.getStatusAt(6) == 'A'); 
    std::cout << "Test 4 passed!" << std::endl;

    std::cout << "All tests passed for RoomBookingSystem!" << std::endl;
}

int main() {
    test_room_booking_system();
    return 0;
}
