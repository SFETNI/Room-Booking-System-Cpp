# Room Booking System

## Objective

The `RoomBookingSystem` project is designed to manage and query room bookings efficiently. This system uses an interval mapping strategy to handle booking periods, allowing you to assign, modify, and query bookings for various time intervals. This approach ensures that overlapping and non-overlapping booking periods are handled accurately, providing a robust solution for room management applications.

### Key Features:
- **Interval Mapping**: Efficiently manage intervals of time where each interval has a specific booking status.
- **Overlap Handling**: Automatically adjust and merge overlapping bookings to maintain accurate records.
- **Efficient Queries**: Quickly retrieve the booking status for any given time period.

## Project Structure

project-folder/
├── Makefile                   
├── src/                      
│   ├── RoomBookingSystem.cpp 
│   └── main.cpp              
├── include/                  
│   └── RoomBookingSystem.h   
└── tests/                   
    └── test_RoomBookingSystem.cpp 



## Building and Running the Project

### On Linux

1. **Navigate to the project folder**:
   ```bash
    - cd path/to/project-folder

    - make
    - ./RoomBookingSystem

### On Windows 
  use mingw32-make

## Example Usage

Here’s an example of how to use the `RoomBookingSystem`:

1. **Initialize the System**: Create an instance of `RoomBookingSystem` with an initial booking status.

   ```cpp```
   RoomBookingSystem bookingSystem('Available');

bookingSystem.assign(1, 3, 'Booked');         // Book room from time 1 to time 3
bookingSystem.assign(4, 6, 'Maintenance');   // Room under maintenance from time 4 to time 6

char status1 = bookingSystem[2]; // 'Booked'
char status2 = bookingSystem[5]; // 'Maintenance'
char status3 = bookingSystem[7]; // 'Available'



